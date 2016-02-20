//outjail.c
//察看囚禁的player
// idea@yqyl

inherit ROOM;
#include <ansi.h>

string atime(int t);

void create()
{
        set("short","囚室外");
        set("long", @LONG

这里是囚室外的房间，通常都是巫师在这里察看犯罪纪录的地方，至于囚犯，
他们出狱的方式是直接被送到武庙。巫师们在这里可以察看在线玩家的犯罪
纪录(consult)，改变囚犯囚禁时间(changetime id newtime)释放被囚的
人(shifang，请慎用)。

LONG );
	set("exits",([
		"enter" : __DIR__"qiushi",
		"out" : "/d/wiz/wizroom",
	]));
	set("no_fight", 1);
	set("no_beg",1);
        setup();
}

void init()
{
	add_action("do_consult","consult");
	add_action("do_release","shifang");
	add_action("do_change","changetime");
}

int do_consult(string arg)
{
	int i,j,inage,howlong,mudage;
	object who;
	string rep,str,s;
	
	who = this_player();
	if(!wizardp(this_player())) return notify_fail("只有巫师可以察看纪录\n");
	
	if (!arg) return notify_fail("consult <id>\n");
	who = find_player(arg);
	if (!who) return notify_fail("没有这个人或不在线。\n");
	rep = "\n";
	rep+= "┌──────────────────────┬─────────┐\n";
	str = sprintf("%s %s(%s)",who->query("title"),who->query("name"),who->query("id"));
	rep+= sprintf("│%-44s│性别：%-12s│\n",str,who->query("gender"));
	rep+= "├──────────────────────┴─────────┤\n";
	if (!who->query("qiushi"))
	{
		rep+= "│"+HIW"此人无囚禁纪录"NOR+"　　　　　　　　　　　　　　　　　　　　　　　　　│\n";
		rep+= "└────────────────────────────────┘\n\n";
	} else
	{
		inage = who->query("qiushi/inage");
		howlong = who->query("qiushi/howlong");
		mudage = who->query("mud_age");
		
		if (file_name(environment(who))!="/d/wiz/qiushi")
		{
		rep+= "│"+HIW"此人现非囚犯也"NOR+"　　　　　　　　　　　　　　　　　　　　　　　　　│\n";
		rep+= "├────────────────┬───────────────┤\n";
		}
		else
		{
		rep+= "│"+HIW"此人正在被囚禁"NOR+"　　　　　　　　　　　　　　　　　　　　　　　　　│\n";
		rep+= "├────────────────┬───────────────┤\n";
		rep+= sprintf("│已被囚禁时间：%-18s│还需被囚：%-20s│\n",atime(mudage-inage),
		atime(inage+howlong*60-mudage));
		rep+= "├────────────────┼───────────────┤\n";
		}
		rep+= sprintf("│总被囚禁次数：%-16s次│总定时间：%-18s分│\n",chinese_number(who->query("qiushi/times")),
		chinese_number(who->query("qiushi/totaltime")));
		rep+= "├────────────────┴───────────────┤\n";
		rep+= "│◎最近囚禁记录◎                                                │\n";
		rep+= "├────────────────────────────────┤\n";
		
		str = who->query("qiushi/note");
		while ((i = strlen(str)) > 0)
  		{
    			j = strsrch (str, "\n");
    			if (j < 0)
    			{
      				s = str;
      				rep+= sprintf("│%s",s);
    			}  
    			s = str[0..j];
    			rep+= sprintf("│%s",s);
    			str = str[j+1..i];
  		}
		rep+= "└────────────────────────────────┘\n\n";
		}
	write(rep);
	return 1;
}

string atime(int t)
{
	int d, h, m, s;
	string time;
	
	if (t<=0) return "——";
	s = t % 60;
	m = t /60;

/*
	if(d) time = chinese_number(d) + "天";
	else time = "";

	if(h) time += chinese_number(h) + "小时";
*/	
	if(m) time = chinese_number(m) + "分";
	else time = "";
	time += chinese_number(s) + "秒";

	return time;
}                                        

int do_release(string arg)
{
	string wizname,criname,result,ttime;
	object qiushi=load_object(__DIR__"qiushi");
	object me= this_player();
	object criminal;
	
	if(!wizardp(me)) return notify_fail("只有巫师可以放人！\n");
	if(!arg || !objectp(criminal = present(arg, qiushi)))
		return notify_fail("你想放谁？\n");
	
	wizname = me->query("name") + "("+me->query("id")+")";
	criname = criminal->query("name") + "("+criminal->query("id")+")";
	
	ttime=ctime(time())[8..strlen(ctime(time()))];
	result = sprintf("%s  %s将%s从牢房里放出\n",ttime,wizname,criname);
	
	criminal->set("qiushi/note",criminal->query("qiushi/note")+result);
	
	qiushi->takeout(criminal);
	qiushi->wizchannel(result);
	
	log_file("qiujin",result);
	
	return 1;
}

int do_change(string arg)
{
	string wizname,criname,result,ttime,id;
	object qiushi=load_object(__DIR__"qiushi");

	object me= this_player();
	object criminal;
	
	int otime,newtime;
	
	if(!wizardp(me)) return notify_fail("只有巫师可以！\n");
	
	if(!arg || arg=="" || sscanf(arg, "%s %d", id, newtime)!=2)
		return notify_fail("指令格式 : changetime <某人> <新的时间>\n");
	if(!objectp(criminal = present(id, qiushi)))
		return notify_fail("你想改谁？\n");
	
	wizname = me->query("name") + "("+me->query("id")+")";
	criname = criminal->query("name") + "("+criminal->query("id")+")";
	
	ttime=ctime(time())[8..strlen(ctime(time()))];
	
	otime = criminal->query("qiushi/howlong");
	criminal->set("qiushi/howlong",newtime);
	
	result = sprintf("%s  %s将%s原囚禁时间%d分改为%d分\n",ttime,wizname,criname,otime,
	newtime);
	
	criminal->set("qiushi/note",criminal->query("qiushi/note")+result);
	
	qiushi->wizchannel(result);
	
	log_file("qiujin",result);
	return 1;
}