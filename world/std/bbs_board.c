// bbsboard.c
// Last modified by jjgod@FYTX. 01/03/06.
/*增强功能留言版：BBS_BOARD
 *增加：回复功能、斑竹功能、整理功能 */

#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

// 最多容纳 100 个贴子
#define MAX_PLAN		500

// 假如贴子超过了 MAX_PLAN，删掉前 50 个
#define DEL_TO		50

// 是否保存所有原来的贴子，是则设为0，否则设为 1
#define SAVE_ALL_OLD_PLAN 0

// 如果需要显示整理情况（很长很长），请：
// #define DEBUG		1
void setup()
{
	string loc;
   	seteuid(getuid());

	if( stringp(loc = query("location")) )
		move(loc);
	set("no_get", 1);
	restore();
}

void init()
{
	add_action("do_post", "post");
	add_action("do_re", "re");
	add_action("do_read", "read");
	add_action("delete_post", "delete");
	add_action("delete_post", "discard");
	add_action("do_banzhu", "banzhu");
	add_action("do_wenxuan", "jinghua");
}

string query_save_file()
{
	string id;

	if( !stringp(id = query("board_id")) ) return 0;
	return DATA_DIR + "board/" + id;
}

string short()
{
	mapping *notes;
	int i, unread, last_read_time;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		return ::short() + " [ 没有任何贴子 ]";

	if( this_player() ) {
		last_read_time = (int)this_player()->query("board_last_read/" + (string)query("board_id"));
		for(unread = 0, i=sizeof(notes)-1; i>=0; i--, unread ++)
			if( notes[i]["time"] <= last_read_time ) break;
	}
	if( unread )
		return sprintf(HIC"%s"NOR" [ "HIW"%d"NOR" 个贴子，"HIR"%d"NOR" 篇未读 ]", ::short(), sizeof(notes), unread);
	else
		return sprintf("%s [ "HIW"%d"NOR" 个贴子 ]", ::short(), sizeof(notes));
}

string long()
{
	mapping *notes;
	int i, j, last_time_read, new_report;
	string msg, myid;

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) ) return query("long");

	write(CLR);
	if( !query("banzhu") ) msg=HBBLU+HIY+"诚征版主中：       ";
	else
	msg=HBBLU+HIY+"版主： "+HIW+"[ "BLINK+HIG+query("banzhu")+NOR+HBBLU+HIW+" ]";
	msg+="             "NOR+HBBLU+WHT+"○"+COLOR_D->replace_color(query("name"));
	msg+=HBBLU+"                                \n";
	msg+=NOR+HIW"阅读文章["HIG"read <n>"HIW"] 阅读回复文章["HIG"read <n>.<n>"HIW"] 发表文章["HIG"post"HIW"] 精华区["HIG"wenxuan"HIW"]\n";
	msg+=HBBLU+HIW"编号　 作者　　　　     时间　　回复  标题         　　　　　 　             \n"NOR;
	last_time_read = this_player()->query("board_last_read/" + (string)query("board_id"));
	for(i=0; i<sizeof(notes); i++) {
		new_report = 0;
		if( arrayp(notes[i]["re"]) ) {
			j = sizeof(notes[i]["re"]);
			while(j--)
				if( notes[i]["re"][j]["time"] <= last_time_read ) break;
			new_report = sizeof(notes[i]["re"]);
		}
		msg += sprintf("%s["WHT"%2d"NOR"]" NOR " "+HIW+( notes[i]["time"] > last_time_read ? "N": "n")+" %-20s"HIG"  [%s] "HIM"%+3d"HIW"  ●"+COLOR_D->get_color(notes[i]["title"])+"%-29s\n"+NOR,
			( notes[i]["time"] > last_time_read ? "": ""),
			i+1,  notes[i]["author"],
			ctime(notes[i]["time"])[4..9],
			new_report,COLOR_D->replace_color(notes[i]["title"],1) );
	}
	msg+=HBBLU+HIY+"["+HIC+NATURE_D->game_time()+HIY"]                                           ["+HIC+this_player()->query("id")+HIY+"] "NOR;
	return msg;
}

void done_post(object me, mapping note, string text)
{
	mapping *notes;
	string msg="";
	int i,j;

	if (me->query("signature")) {
		note["msg"]=COLOR_D->replace_color(text+"\n---------------------------------\n"+me->query("signature"),1);
	}
	else note["msg"]=COLOR_D->replace_color(text,1);

	notes = query("notes");
	if( !pointerp(notes) || !sizeof(notes) )
		notes = ({note });
	else
		notes += ({ note });

	set("notes", notes);
	save();
	tell_object(me, HIW"新贴子完成。\n"NOR);

	if( query("news") )
	{
        message("news",HIG+"【新闻频道】新闻小姐："HIC"「"+MUD_NAME+HIC"」"HIG"有了新的新闻，请用"HIY"news"HIG"查看。\n"+NOR,users());
	tell_object(me, "新闻发表完毕。\n");
	}
	if (sizeof(query("notes"))>MAX_PLAN) {
	tell_object(me, HIR"贴子数目超量，正在整理……\n"NOR);
		for (i=0;i<DEL_TO;i++) {
// 原文内容
			msg+=sprintf(
			"[ "HIW"编号："NOR"%2d ] [ "HIW"作者："NOR"%s(%s) ] [ "HIW"时间："NOR"%-19s ]\n[ "
			HIW"标题："NOR"%-54s ]\n────────────────────────────────\n%s\n"
			"──────────────────────────["HIW" 本 篇 完 "NOR"]\n",
			i+1,
			notes[i]["author"],notes[i]["owner"],
			ctime(notes[i]["time"])[0..9],
			notes[i]["title"],
			notes[i]["msg"],);
// 回复内容
			if (sizeof(notes[i]["re"])) {
				for (j=0;j<sizeof(notes[i]["re"]);j++) {
					msg+=sprintf(
					"\n[ "HIW"回复编号："NOR"%2d] [ "HIW"回复标题："NOR"%-34s ] \n"
					"────────────────────────────────\n"
					"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
					HIW"作者："NOR" %s(%s) %-7s]\n",
					j+1,
					notes[i]["re"][j]["title"],
					notes[i]["re"][j]["msg"],
					ctime(notes[i]["re"][j]["time"]),
					notes[i]["re"][j]["author"],
					notes[i]["re"][j]["owner"],"");
				}
			}
		}
#ifdef DEBUG
		me->start_more(msg);
#endif
// 50 以前的贴子将保存到 /data/board/这里的board_id 文件中
		write_file(DATA_DIR+"board/"+query("board_id")+".old",msg,SAVE_ALL_OLD_PLAN);
// 删除目前 board 里的 50 以前的贴子
		notes = notes[DEL_TO..sizeof(notes)-1];
		set("notes",notes);
		save();
		tell_object(me, HIR"……整理完毕，删除 "HIW+(DEL_TO+1)+HIR" 号以前的贴子。\n"NOR);
	}
	return;
}

void done_re(object me, mapping report, int project, string text)
{
	mapping *notes, *reports;
// 支持签名和颜色
	if (me->query("signature")) {
		report["msg"]=COLOR_D->replace_color(text+"\n---------------------------------\n"+me->query("signature"),1);
	}
	else report["msg"]=COLOR_D->replace_color(text,1);

	notes = query("notes");
	reports = notes[project]["re"];
	if( !arrayp(reports) )	reports = ({ report });
	else reports += ({ report });

	notes[project]["re"] = reports;
	notes[project]["time"] = time();

	set("notes", notes);
	tell_object(me, HIW"回复完毕。\n"NOR);

	save();
	return;
}

int do_post(string arg)
{
	mapping note;

	if( (query("env/invisibility") || query("wizard")) && !wizardp(this_player())) return 0;

	if(!arg) return notify_fail("新贴子请指定一个标题。\n");
	if( strlen(arg)>24 ) return notify_fail("标题过长，还是写个短点的标题吧！\n");
	note = allocate_mapping(5);
	note["title"] = arg;
	note["owner"] = this_player()->query("id");
	note["author"] = COLOR_D->clean_color(this_player()->name(1));
	note["time"] = time();
	this_player()->edit( (: done_post, this_player(), note :) );
	return 1;
}

int do_re(string arg)
{
	int num;
	string title;
	mapping note, *notes;

	if(!arg || sscanf(arg, "%d.%s", num, title)!=2 )
		return notify_fail("指令格式：re <贴子编号>.<回复标题>\n");

	notes = query("notes");
	if( !arrayp(notes) || num < 1 || num > sizeof(notes) )
		return notify_fail("没有这个贴子。\n");

	note = allocate_mapping(5);
	note["title"] = title;
	note["owner"] = this_player()->query("id");
	note["author"] = this_player()->name(1);
	note["time"] = time();
	this_player()->edit( (: done_re, this_player(), note, num-1 :) );
	return 1;
}

int do_read(string arg)
{
	int num, rep, last_read_time,i,last;
	mapping *notes;
	string myid,msg,file;
	object me=this_player();

	last_read_time = me->query("board_last_read/" + query("board_id"));
	myid	= query("board_id");
	notes	= query("notes");

	if( !pointerp(notes) || !sizeof(notes) )
		return notify_fail("板子上目前没有任何贴子。\n");

	if( !arg ) return notify_fail("指令格式：read <贴子编号>[.<回复编号>]|new|next|old\n");

// 显示以前备份的旧贴子
	if (arg=="old") {
		file=DATA_DIR+"board/"+query("board_id")+".old";
		if (file_size(file)<=0) return notify_fail("对不起，目前本版没有保存的旧贴。\n");
		else {
			msg=read_file(file);
			me->start_more(msg);
			return 1;
		}
	}
// 显示未读的贴子
	if( arg=="new" || arg=="next" ) {
		if( !intp(last_read_time) || undefinedp(last_read_time) )
			num = 1;
		else
		for(num = 1; num<=sizeof(notes); num++)
			if( notes[num-1]["time"]>last_read_time) break;

	} else if( sscanf(arg, "%d.%d", num, rep)==2 ) {
		if( num < 1 || num > sizeof(notes) ) return notify_fail("没有这个贴子。\n");
		else num--;
		if( rep < 1 || rep > sizeof(notes[num]["re"]) ) return notify_fail("没有这个回复。\n");
		else rep --;
		me->start_more( sprintf(
		"[ "HIW"编号："NOR"%2d | "HIW"回复编号："NOR"%2d] [ "HIW"原题："NOR"%-27s ] \n"
		"[ "HIW"回复标题："NOR"%-50s ]\n────────────────────────────────\n"
		"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
		HIW"作者："NOR" %s(%s) %-7s]\n",
			num + 1, rep + 1,
			COLOR_D->replace_color(notes[num]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][rep]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][rep]["msg"],1),
			ctime(notes[num]["re"][rep]["time"]),
			notes[num]["re"][rep]["author"],
			notes[num]["re"][rep]["owner"],"") );

		if( notes[num]["time"] > last_read_time )
			me->set("board_last_read/" + query("board_id"),
				notes[num]["time"]);

		return 1;
	} else if( !sscanf(arg, "%d", num) )
		return notify_fail("你要读第几个贴子的回复？\n");

	if( num < 1 || num > sizeof(notes) )
		return notify_fail("没有这个贴子。\n");
	num--;
	msg=sprintf(
	"[ "HIW"编号："NOR"%2d ] [ "HIW"作者："NOR"%s(%s) ] [ "HIW"时间："NOR"%-19s ]\n[ "
	HIW"标题："NOR"%-54s ]\n────────────────────────────────\n%s\n"
	"──────────────────────────["HIW" 本 篇 完 "NOR"]\n",
		num + 1,
		notes[num]["author"],notes[num]["owner"],
		ctime(notes[num]["time"])[0..9],
		COLOR_D->replace_color(notes[num]["title"],1),
		COLOR_D->replace_color(notes[num]["msg"],1));
// 显示回复的数目
	if (sizeof(notes[num]["re"])&&me->query("env/show_reply")!="all") msg+=sprintf(HIW"回复："NOR"%d 份。\n",sizeof(notes[num]["re"]));
// 显示最后的一个回复
	if (me->query("env/show_reply")=="last") {
		last=sizeof(notes[num]["re"])-1;
		msg+=sprintf(
			"\n[ "HIW"回复编号："NOR"%2d] [ "HIW"回复标题："NOR"%-34s ] \n"
			"────────────────────────────────\n"
			"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
			HIW"作者："NOR" %s(%s) %-7s]\n",
			last+1,
			COLOR_D->replace_color(notes[num]["re"][last]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][last]["msg"],1),
			ctime(notes[num]["re"][last]["time"]),
			notes[num]["re"][last]["author"],
			notes[num]["re"][last]["owner"],"");
	}
// 显示所有的回复
	if (me->query("env/show_reply")=="all") {
		for (i=0;i<sizeof(notes[num]["re"]);i++) {
			msg+=sprintf(
		"\n[ "HIW"回复编号："NOR"%2d] [ "HIW"回复标题："NOR"%-34s ] \n"
		"────────────────────────────────\n"
		"%s\n────────────────────────────────\n[ "HIW"时间："NOR"%s ] [ "
		HIW"作者："NOR" %s(%s) %-7s]\n",
			i+1,
			COLOR_D->replace_color(notes[num]["re"][i]["title"],1),
			COLOR_D->replace_color(notes[num]["re"][i]["msg"],1),
			ctime(notes[num]["re"][i]["time"]),
			notes[num]["re"][i]["author"],
			notes[num]["re"][i]["owner"],"");
		}
	}
	me->start_more(msg);

	if( notes[num]["time"] > last_read_time )
		me->set("board_last_read/" + query("board_id"),
			notes[num]["time"]);

	return 1;
}

int do_banzhu(string arg)
{
	if (!arg) return notify_fail("指令格式： banzhu <版主id>\n");
	if (!stringp(arg)||strlen(arg)<3) return notify_fail("没有这个人。\n");
	if (query("banzhu")==arg) return notify_fail("目前的版主就是 "+arg+"，不需要设置。\n");
	if (SECURITY_D->get_status(this_player(1)) != "(admin)") return notify_fail("你不是天神，不可以设置版主。\n");
	set("banzhu",arg);
	save();
	write("设置 "HIW+arg+NOR" 为"+name()+"版主成功。\n");
	return 1;
}

int delete_post(string arg)
{
	mapping *notes;
	int num,re_num;

	if(!arg ||sscanf(arg, "%d.%d",num,re_num)<1)
		return notify_fail("指令格式：delete <贴子编号>[.<回复编号>]\n");
	notes = query("notes");
	if( !arrayp(notes)|| num <1 || num > sizeof(notes))
		return notify_fail("没有这张贴子。\n");
	else if(re_num) {
		if (re_num<1||!arrayp(notes[num-1]["re"])||re_num > sizeof(notes[num-1]["re"]))
			return notify_fail("没有这张回复。\n");
		else {
			num--;
			re_num--;
			if( notes[num]["re"][re_num]["owner"] != (string)this_player(1)->query("id")
			&&query("banzhu")!=this_player(1)->query("id")
			&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)")
				return notify_fail("这个回复不是你写的，你又不是版主。\n");
			else {
				notes[num]["re"]=notes[num]["re"][0..re_num-1] + notes[num]["re"][re_num+1..sizeof(notes[num]["re"])-1];
				set("notes", notes);
				save();
				write("删除第 " + (num+1) + " 号贴子的第 "+ (re_num+1)+" 号回复....Ok。\n");
				return 1;
			}
		}
	}
	else {
		num--;
		if( notes[num]["owner"] != (string)this_player(1)->query("id")
		&&query("banzhu")!=this_player(1)->query("id")
		&&	(string)SECURITY_D->get_status(this_player(1)) != "(admin)" )
			return notify_fail("这个贴子不是你写的，你又不是版主。\n");

		notes = notes[0..num-1] + notes[num+1..sizeof(notes)-1];
		set("notes", notes);
		save();
		write("删除第 " + (num+1) + " 号贴子....Ok。\n");
		return 1;
	}
}

int do_wenxuan(string arg)
{
	object me=this_player();
	int num,i;
	mapping *notes= query("notes");
	string msg,file_name;

	if (!wizardp(me)&&query("banzhu")!=getuid(me)) return notify_fail("你没有这个权力！\n");
	if (!arg) return notify_fail("你想把哪篇文章放入精华区？\n");
	if (sscanf(arg,"%d",num)!=1) return notify_fail("格式：jinghua <文章编号>\n");
	seteuid(getuid());
	if (num>sizeof(query("notes"))||!arrayp(notes)|| num <1) return notify_fail("没有这篇文章！\n");
		else {
		num--;
		msg=sprintf(
		"%s \n\t   ——由 "HIW"%s(%s)"NOR" 于 "HIW"%-10s"NOR" 发表在 "HIW"%s"NOR" \n"
		"────────────────────────────────\n%s\n"
		"──────────────────────────["HIW" 本 篇 完 "NOR"]",
		notes[num]["title"],
		notes[num]["author"],notes[num]["owner"],
		ctime(notes[num]["time"])[0..9],
		name(),
		notes[num]["msg"],);

		if (sizeof(notes[num]["re"])) {
			for (i=0;i<sizeof(notes[num]["re"]);i++) {
				msg+=sprintf(
				"\n\n本文回复["HIW"%2d"NOR"]："NOR"%-34s\n\t   ——由 "HIW"%s(%s)"NOR" 发表于 "HIW"%-10s"NOR"\n"
				"────────────────────────────────\n"
				"%s\n────────────────────────────────\n",
				i+1,
				notes[num]["re"][i]["title"],
				notes[num]["re"][i]["author"],
				notes[num]["re"][i]["owner"],
				ctime(notes[num]["re"][i]["time"]),
				notes[num]["re"][i]["msg"],);
			}
		}

		file_name="/data/wenxuan/"+localtime(time())[5]+"/"+(sizeof(get_dir(DATA_DIR+"wenxuan/"+localtime(time())[5]+"/"))+1)+".w";

		write("正在写入"+file_name+"……");
		write(msg);
		if ( write_file(file_name,msg) ) write(HIG"\n写入成功！\n"NOR);
		else write(HIR"\n写入失败,请与巫师联系!\n"NOR);
		return 1;
	}
}