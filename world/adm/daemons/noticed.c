//noticed.c modify by gump 2000-9-23 0:17

#include <ansi.h>
inherit F_SAVE;
#define MAX_NUM		5
private void change_notice(string type, object who, string notice_type);
private void select_type(string type, object who);
private void show_notice(string type, int num);
private void view_notice(string type, object who, string notice_type);
private void delete_notice(string type , object who, string notice_type, int num);
private void add_notice(object who, string notice_type, string text);
private int query_notice_num(string type);
private string replace_info(string info);

private mapping * player_notice;
private mapping * wizard_notice;

string query_save_file()
{
	return DATA_DIR+"daemons/noticed";
}

void reset_notice()
{
	player_notice=0;
	wizard_notice=0;
	save();
}
void create()
{
	if(!restore())
		reset_notice();
}

void begin(object who)
{
	select_type("", who);
	return;
}
private void select_type(string type, object who)
{
	string notice_type="";

	if(!type||(type!="1" && type!="2" && type!="3"))
	{	
		write(@TEXT
连线通知使用：
1). 玩家连线通知
2). 巫师连线通知
3). 退出
请按数字进入。
TEXT);
		printf("您想要选择的是：");
		input_to("select_type", who);
		return;
	}
	if(type=="1")
		notice_type="player";
	else if(type=="2")
		notice_type="wizard";
	if(type=="1"||type=="2")
	{
		change_notice("", who, notice_type);
		return;
	}
	if(type=="3")
		return;
	select_type("", who);
	return;
}

private void change_notice(string type, object who, string notice_type)
{
	if(!type||type=="")
	{
		printf("当前选择：[%s连线通知]\n", notice_type=="player"? 
			"玩家":"巫师");
		show_notice(notice_type, -1);
		write(@TEXT
1). 查看现有连线通知的详细内容
2). 添加一条连线通知
3). 退出
请按数字进入。
TEXT);
		printf("您想要选择的是：");
		input_to("change_notice", who, notice_type);
		return;
	}
	if(type=="1")
	{
		if(!query_notice_num(notice_type))
		{
			write("目前没有任何连线通知。\n");
			change_notice("", who, notice_type);
			return;
		}
		view_notice("", who, notice_type);
		return;
	}
	if(type=="2")
	{
		if(query_notice_num(notice_type)>MAX_NUM)
		{
			write("目前连线通知已经过多，请删除一些老的再加。\n");
			change_notice("", who, notice_type);
			return;
		}
		write("请输入连线通知的详细内容，不支持ANSI颜色代码：\n");
		who->edit((:add_notice, who, notice_type:));
		return;
	}
	if(type=="3")
		return;
	change_notice("", who, notice_type);
	return;
}

private void add_notice(object who, string notice_type, string text)
{
	string master;
	int time;
	mapping notice;
	
	if(!text||strlen(text)<4)
	{
		write("内容太过于简短，添加失败。\n");
		change_notice("", who, notice_type);
		return;
	}
	if(strlen(text)>200)
	{
		write("内容太过于烦琐，添加失败。\n");
		change_notice("", who, notice_type);
		return;
	}
	notice=allocate_mapping(4);
	master=geteuid(who);
	time=time();
	notice["master"]=master;
	notice["name"]=who->name(1);
	notice["time"]=time;
	notice["info"]=replace_info(text);
	if(notice_type=="player")
		if(sizeof(player_notice))
			player_notice+=({notice});
		else player_notice=({notice});
	else if(sizeof(wizard_notice))
			wizard_notice+=({notice});
		else wizard_notice=({notice});
	save();
	write("成功添加一条连线通知。\n");
	change_notice("", who, notice_type);
	return;
}
private void view_notice(string type, object who, string notice_type)
{
	int choice;
	
	if(!type||type=="")
	{
		printf("当前选择：[%s连线通知]\n", notice_type=="player"? 
			"玩家":"巫师");
		show_notice(notice_type, 1000);
		printf("%d). 退出\n", query_notice_num(notice_type)+1);
		printf("请按数字进入：");
		input_to("view_notice", who, notice_type);
		return;
	}
	sscanf(type, "%d", choice);
	if(!choice||choice>query_notice_num(notice_type)+1)
	{
		view_notice("", who, notice_type);
		return;
	}
	if(choice==query_notice_num(notice_type)+1)
		return;
	delete_notice("", who, notice_type, choice-1);
	return;
}

private void delete_notice(string type , object who, string notice_type, int num)
{
	mapping * notice;
	if(!type||type=="")
	{
		show_notice(notice_type, num);
		write(@TEXT
1). 删除此条连线通知
2). 退回到上级菜单
3). 退出
TEXT);
		printf("您要选择的是：");
		input_to("delete_notice", who, notice_type, num);
		return;
	}
	if(type=="1")
	{
		if(notice_type=="player")
			notice=player_notice;
		else notice=wizard_notice;
		if(SECURITY_D->get_wiz_level(who)<
			SECURITY_D->get_wiz_level(notice[num]["master"]))
		{
			write("你没有删除这条通知的权利。\n");
			view_notice("", who, notice_type);
			return;
		}
		notice-=({notice[num]});
		if(notice_type=="player")
			player_notice=notice;
		else wizard_notice=notice;
		save();
		write("删除成功！\n");
		view_notice("", who, notice_type);
		return;
	}
	if(type=="2")
	{
		view_notice("", who, notice_type);
		return;
	}
	if(type=="3")
		return;
	delete_notice("", who, notice_type, num);
	return;
}
private void show_notice(string type, int num)
{
	mapping * notice;
	int max, i;
	string desc;
	
	if(type=="player")
		notice=player_notice;
	else notice=wizard_notice;
	max=sizeof(notice);
	if(num==-1 || num>max)
		if(!max)
			desc="目前没有任何连线通知。\n";
		else desc="目前有"+HIY+chinese_number(max)+NOR+"条连线通知。\n";
	if(num>max && max)
		for(i=0;i<max;i++)
			desc+=sprintf("%d). %s(%s) 于 %s 留\n",
				i+1, 
				notice[i]["name"],
				capitalize(notice[i]["master"]), 
				ctime(notice[i]["time"]));
	if(num!=-1&&num<=max)
	{
		
		desc=HIY"============================================================\n"NOR;
		desc+=sprintf("时间：%s %28s\n", 
			ctime(notice[num]["time"]),
			sprintf("发表：%s(%s)",
			notice[num]["name"],
			capitalize(notice[num]["master"])));
		desc+=HIR"------------------------------------------------------------\n"NOR;
		desc+=notice[num]["info"];
		desc+=HIY"============================================================\n"NOR;
		
	}
	write(desc);
	return;
}

private int query_notice_num(string type)
{
	mapping * notice;
	if(type=="player")
		notice=player_notice;
	else notice=wizard_notice;
	return sizeof(notice);
}

private string replace_info(string info)
{
	int i, flag=0;
	string tmp="";
	
	info=replace_string(info, "\n", "");
	for(i=0;i<strlen(info);i++)
	{
		flag++;
		tmp+=info[i..i];
		if(flag==59 && info[i]<=160)
			flag=0;
		else if(flag==60)
			flag=0;
		if(!flag)
			tmp+="\n";
	}
	if(flag)
		tmp+="\n";
	return tmp;	
}

string show_all_notice(string type)
{
	mapping * notice;
	string desc;
	int i;
	
	if(type=="player")
		notice=player_notice;
	else notice=wizard_notice;
	if(!sizeof(notice))
		return 0;
	if(type=="player")
		desc=HIY"＝＝＝＝＝＝＝＝＝＝＝"HIY+BCYN"梦幻西游"NOR+HIW"·"HIR"连线通知"HIY"＝＝＝＝＝＝＝＝＝＝\n"NOR;
	else desc=HIY"＝＝＝＝＝＝＝＝＝＝＝"HIY+BCYN"梦幻西游"NOR+HIW"·"HIR"巫师通知"HIY"＝＝＝＝＝＝＝＝＝＝\n"NOR;
	for(i=0;i<sizeof(notice);i++)
	{
		desc+=sprintf("时间：%s %28s\n", 
			ctime(notice[i]["time"]),
			sprintf("发表：%s(%s)",
			notice[i]["name"],
			capitalize(notice[i]["master"])));
		desc+=YEL+notice[i]["info"]+NOR;
		if(i!=sizeof(notice)-1)
			desc+=HIR"============================================================\n"NOR;
	}
	desc+=HIY"＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"NOR;
	return desc;
}

