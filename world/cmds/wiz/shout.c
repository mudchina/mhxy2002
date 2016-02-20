// shout.c
// By tianlin@mhxy for 2001.9.21从新改写
// 请不要抄,谢谢
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        if((int)me->query("max_force") < 2000&& !wizardp(me)  )
                return notify_fail("你的内力火候不够！\n");
        if((int)me->query("force") < 800&& !wizardp(me)  )
                return notify_fail("都没有内力了快别再叫了！\n");
        if((int)me->query("daoxing") < 686000&& !wizardp(me)  )
                return notify_fail(HIB"你的道行不够,无法领会到"HIY"shout"HIB"的奥妙之处！\n"NOR);
        if((int)me->query("sen") < 500&& !wizardp(me)  )
                return notify_fail(HIB"你快累死了,先休息一下吧\n"NOR);
	 if( time()-(int)me->query_temp("shout_temp") < 8&& !wizardp(me) )
                return notify_fail(RED"你刚刚叫完,还是等会在叫吧！\n"NOR);
        if (!arg) return notify_fail("你想要大叫什么？\n");
          shout(HIR + me->name() +  "纵声长啸："HIW+ arg + "\n" NOR);//this is by tianlin 2001.
          write(HIR "你纵声长啸："HIW+ arg + "\n" NOR);
	 if( !wizardp(me) )
          me->add("force", -100);
	 if( !wizardp(me) )
          me->add("sen", -500);
	 if( !wizardp(me) ) 
          me->set_temp("shout_temp",time());
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话. 条件 (内力修为20年以上,要求道行一日千里
使用一次掉500点精神,100点内力.)
 
see also : tune
HELP
    );
    return 1;
}
