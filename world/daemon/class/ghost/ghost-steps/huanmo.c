#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 int myexp,yourexp,lvl;
 int sen;
 object weapon;
 if( !target ) target = offensive_target(me);
if( !target||!target->is_character()||!me->is_fighting(target) )
  return notify_fail(HIC"［"HIR"幻魔鬼影"HIC"］"NOR"只能对战斗中的对手使用。\n");
 weapon = me->query_temp("weapon");
 myexp = (int) me->query("combat_exp");
 yourexp = (int) target->query("combat_exp");
lvl = (int) me->query_skill("ghost-steps")/30;
msg = RED "$N使出鬼影迷踪步法中的绝学［幻魔鬼影］，\n$n"NOR+RED"周围出现重重鬼影，一时黑雾弥漫。" NOR;
if(random(myexp)>yourexp/2)
 {
 message_vision(msg + "\n", me, target);
  msg = "结果$n"NOR"什么都看不见了！\n";
  message_vision(msg, me, target);
target->start_busy(lvl);
me->start_busy(1);
 }
 else
{
msg = "你失败了。\n";
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
   me->start_busy(2);
}
 return 1;
}
