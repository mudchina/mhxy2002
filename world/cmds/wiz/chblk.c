// channel block command..
// Write by JackyBoy@cctx 1999/2/8

#include <globals.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string who, ch_name,str;
	string* channels=({"all","rumor","chat","es","party","new","wiz","arch","gwiz","gbwiz"});

	if (!arg)
		return notify_fail("语法: chblk <玩家id> <频道名>\n");
	if (sscanf(arg, "%s %s", who, ch_name) != 2)
	{
		ch_name = "";
		if (sscanf(arg, "%s", who) != 1)
			return  notify_fail("语法: chblk <玩家id> <频道名>\n");
	}
	ob = LOGIN_D->find_body(who);
	if (!ob) return notify_fail("这个人不在！\n");
	if (wizardp(ob)) return notify_fail("不能关闭巫师的频道。\n");
	if (ch_name == "" || ch_name == " ") 
	{
		str=ob->query("name")+"("+ob->query("id")+")的频道关闭情况如下：\n";
		if ( (time() - (int)ob->query("chblk_channel/all")) < 3600)
			str+=(string)ob->query("name")+"的所有频道都被关闭了。\n";
		if ( time() - (int)ob->query("chblk_channel/rumor") < 3600)
			str+=(string)ob->query("name")+"的谣言频道被关闭了。\n";
		if ( time() - (int)ob->query("chblk_channel/chat") < 3600)
			str+=(string)ob->query("name")+"的闲聊频道被关闭了。\n";
		if ( time() - (int)ob->query("chblk_channel/new") < 3600)
			str+=(string)ob->query("name")+"的新手频道被关闭了。\n";
		if ( time() - (int)ob->query("chblk_channel/party") < 3600)
			str+=(string)ob->query("name")+"的门派频道被关闭了。\n";
		if ( time() - (int)ob->query("chblk_channel/es") < 3600)
			str+=(string)ob->query("name")+"的网际频道被关闭了。\n";
		if(str==(ob->query("name")+"("+ob->query("id")+")的频道关闭情况如下：\n"))
			str+=ob->query("name")+"没有被关闭的频道。\n";
		tell_object(me,str);
	}
	else
	if(member_array(ch_name,channels)!=-1)
	{
		ob->set("chblk_channel/"+ch_name,time());
		if(ch_name!="all")
			tell_object(me,ob->query("name")+"的"+ch_name+"频道被关闭了。\n");
		else
			tell_object(me,ob->query("name")+"的所有频道都被关闭了。\n");

	}
	else
		return notify_fail("没有这个频道！\n");
	return 1;
}

int help(object me)
{
write(@HELP
指令格式 : chblk <某人> <频道名>

此命令将关闭某人的某个频道。
<频道名>：可以是rumor、chat等或all封闭所有频道。
如果不提供频道名，则显示某人当前的频道状态。 

HELP
    );
    return 1;
}
