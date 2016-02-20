//shoot.c 灵弹
//created by foc,1-7-01
//特点说明：杀伤力极强（后期），不过使用的限制相应的就多。

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
    int damage, myexp, urexp, mysk, ursk, chance;
    if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me )
    return notify_fail("你要对谁用灵弹？\n");
    if( (int)me->query_skill("lingguang-quan",1)<80)
    return notify_fail("你对灵光拳的使用还不熟练。\n");
    if((int)me->query_skill("segokee",1)<10)
    return notify_fail("你试着将灵气聚集起来发射灵弹，但是没有成功。\n");
    if((int)me->query_skill("spiritforce", 1) < 80 )
    return notify_fail("你试着将灵气聚集起来发射灵弹，但是没有成功。\n");    
    if (me->query_skill_mapped("force") != "spiritforce"||
me->query_skill_mapped("force") != "segokee")
    return notify_fail("你现在使用的气不对。\n");
    if( (int)me->query("max_force") < 1200 || (int)me->query("kee")<300 || (int)me->query("force")<400 )
    return notify_fail("灵弹是要消耗很多灵气的，你现在的灵气量还不够。\n");
    if( (int)me->query("kee") < 200) 
    return notify_fail("你突然觉得自己的体力不足以负担这招的消耗，还是爱惜生命的好！\n");
    if((int)me->query("combat_exp")<200000 || (int)me->query("daoxing")<200000)
    return notify_fail("你的修为太低了。\n");
    else
{
    mysk=(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*10+(int)me->query_skill("unarmed",1)+(int)me->query_skill("dodge",1);
    ursk=(int)target->query_skill("parry",1)+(int)target->query_skill("dodge",1);
    myexp=(int)me->query("combat_exp");
    urexp=(int)target->query("combat_exp");
    damage=5*mysk-ursk+random(myexp/1000)-random(urexp/3000);
    me->add("force",-400);
    message_vision(HIW "$N的右手食指上不断聚集着灵气，强大的力量也随之集中。\n接着，$N以左手托着右手，大喝一声：“灵弹！”一个巨大的\n光球立刻被发射出来，朝着$n直冲过去！\n"  NOR,me,target);
{
    if(random(myexp)>random(myexp/2+urexp/2) || target->is_busy())
{
    if((int)target->query_skill("segokee",1)*6 > (int)me->query_skill("spiritforce",1))
{
    message_vision(HIY "结果$n全身放出金黄色的圣光气，将$N的灵弹攻\n势完全挡住了，没有受到一点伤害。\n" NOR,me,target);
    target->add("force",-50);
    me->start_busy(2);
    tell_object (me, "对手比较强，看来用这招不能奏效。\n");
    tell_object (target, "好机会，趁此攻击！\n");
    return notify_fail("试试其他的招式，也许有有用的。\n");
}
    if(random((int)me->query_skill("spiritforce",1))<random((int)target->query_skill("spiritforce",1)/5*3) && !target->is_busy())
{
    message_vision(HIC "但是$n将自己的灵气集中在双掌之上，全力将$N的灵弹引开了。\n" NOR,me,target);
    target->add("force",-200);
    me->start_busy(3);
    tell_object (target, "好机会，趁此攻击！\n");
    return notify_fail("对手的灵气也不弱，看来要换个方式攻击。\n");
}
    else
{
    message_vision(GRN "$n终于躲闪不及，被$N的灵弹打了个正着，\n整个人像一捆稻草一样横飞开去！\n");
    me->start_busy(3);
    target->receive_damage("kee",damage);
    target->receive_wound("kee",damage);
    COMBAT_D->report_status(target,0);
}
}
}
}
    return 1;
}
