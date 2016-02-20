//mindshock.c 圣光念杀技
//created by foc,02-7-01

#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int chance, mysk, yoursk, myexp, yourexp, damage, n;
    if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你对谁使用念杀技？\n");
    if((int)me->query_skill("segokee",1)<30)
    return notify_fail("你的圣光气还没强大到可以这个地步。\n");
    if((int)me->query("combat_exp")<1600000)
    return notify_fail("你尚未身经百战，别玩这个比较好。\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("你的修为还不足以使用这招。\n");
    else
{
    mysk=(int)me->query_skill("segokee",1)*5+(int)me->query("force_factor")+(int)me->query_skill("force",1);
    yoursk=(int)target->query_skill("dodge",1)/2+(int)target->query_skill("force",1)*2+(int)target->query("apply/armor")/2;
    damage=(mysk-yoursk)+random(myexp/1000);
    if(damage<0 || damage=0) damage=1;
    myexp=(int)me->query("combat_exp");
    yourexp=(int)target->query("combat_exp")/2;
    chance=mysk/6+random(10);
    n=damage*chance;
    message_vision(HIY "$N微一凝神，全身的圣光气立刻发生了变化。\n$N双眼放出金黄色的光，接着身上的气突地\n分出几股来，催动空气无声无息地向$n袭去！\n" NOR,me,target);
    me->add("force",-300);
    me->start_busy(random(3));
    if(random(myexp)>random(myexp/2+yourexp/2) || target->is_busy())
{
    message_vision(GRN "结果$n胸口中了"+chinese_number(chance)+"处$N的念杀攻击，胸口的肌肉深陷，受伤不轻！\n" NOR,me,target);
    target->receive_damage("kee",n);
    target->receive_wound("kee",n);
    COMBAT_D->report_status(target,0);
    tell_object (target, "你感到胸口一阵剧痛，顿时浑身使不上力。\n");
    target->start_busy(random(3));
    target->kill_ob(me);
    me->kill_ob(target);
}
    else
{
    message_vision(GRN "但是$n似乎已经觉得有什么不对劲，竟然鬼使神差地躲了开去。\n" NOR,me,target);
    me->start_busy(1);
    message_vision(GRN "$n对$N大喝道：“死妖怪，想搞什么破坏！”\n" NOR,me,target);
    target->kill_ob(me);
    me->kill_ob(target);
}
}
    return 1;
}
