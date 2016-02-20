//By tianlin@Mhxy for 2002.1.3
 
#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;
 
int main(object me, string str)
{  
  object who;
  if (!str) return notify_fail ("usage:xing <id>\n");
  who = LOGIN_D->find_body(str);
  if (!who){ 
  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("这里没有"+str+"\n");
  }
  who->remove_call_out("revive");
  who->revive();
  write("Ok.\n");
  return 1;
}
 
int help(object me)
{
   write(@HELP

指令格式: xing <id>
 
使某人立刻从昏迷中清醒过来

HELP
   );
   return 1;
}
