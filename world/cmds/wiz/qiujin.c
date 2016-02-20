// /cmds/wiz/qiujin.c
// idea@yqyl
////By waiwai@2000/12/26 部分优化

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me,string arg)
{
	string id,reason,wizname,criname,result,ttime;
	int howlong,i;
	object criminal;
	
	if(!arg || arg=="" || sscanf(arg, "%s %d %s", id, howlong,reason)!=3)
		return notify_fail("指令格式 : qiujin <某人> <时间> <原因>\n");
		
	criminal = find_player(id);
	if (!criminal) return notify_fail("没有这个人\n");
	if (wizardp(criminal)) return notify_fail("巫师有问题，还是给大神们报告吧。\n");
	
	wizname = me->query("name") + "("+me->query("id")+")";
	criname = criminal->query("name") + "("+criminal->query("id")+")";
	
	ttime=ctime(time())[8..strlen(ctime(time()))];
	
	criminal->set("qiushi/howlong",howlong);
	
	result = sprintf("%s因为（%s）将%s关入囚室%d分钟\n",
			wizname,reason,criname,howlong);

       CHANNEL_D->do_channel(this_object(), "rumor",
                ""HIG+criname+HIM"因"HIY+reason+HIM"被送进了"+HIW"囚室 "HIM"囚禁时间为 "+howlong+"分钟！！！"NOR);
			
	criminal->set("qiushi/temp",result);
//	tell_object(criminal,result);
	criminal->move("/d/wiz/qiushi");
	
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : qiujin <某人> <时间> <原因>

时间以分钟为单位，如果为0则表示不自动放出，请慎用。
原因一定要详细写。

例子	qiujin tryid 60 chat刷屏
HELP	);
	return 1;
}
