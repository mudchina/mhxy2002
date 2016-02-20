// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到这个生物。\n");
	message_vision("$N手一挥，$n应声摔倒在地上！！\n",me,ob);
	ob -> unconcious();
	return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: uncon <生物>
 
使生物昏迷不醒
HELP
   );
   return 1;
}
