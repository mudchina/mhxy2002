//穿心剑
//by swagger

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int meexp, youexp, extra;
        object weapon;
     
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("穿心剑只能在战斗中使用\n");
   if((int)me->query_skill("liangyi-sword",1) < 60)
    return notify_fail("你的剑法等级不够!\n");
   if((int)me->query_skill("wuxiangforce",1) < 60)
    return notify_fail("你的内功等级不够!\n");
 if (me->query_temp("chuan_busy")) 
      return notify_fail("你现在再用这招会有危险!\n");
   if( (int)me->query("force") < 1000)
   return notify_fail("你的内力太弱,不能以气御剑!\n");
        if(! me->query_temp("weapon"))
                return notify_fail("掌中无剑，怎能用穿心剑!\n");

    meexp = (int)me->query("combat_exp");
    youexp = (int)target->query("combat_exp");
   msg = WHT
"\n$N一声长笑，随空斜斜刺出毫无章法的一剑!\n
$n一楞之间,那剑却快如闪电的刺向$n的心脏!!\n\n" NOR;
message_vision(msg, me ,target);
    if( random(meexp*4) > youexp)
{
msg = HIR"\n只听$n一声惨嚎,$N的剑已经穿心而过!!\n" NOR;
message_vision(msg, me ,target);
target->start_busy(1+random(2));
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
}
else {
msg = HIR"\n$n就地一滚，闪过这毒辣的穿心一剑。\n" NOR;
message_vision(msg, me ,target);
me->start_busy(1+random(1));
}
me->set_temp("chuan_busy",1);
call_out("remove_effect",3+random(3),me);
me->add("force",-100);
        return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("chuan_busy");
}
