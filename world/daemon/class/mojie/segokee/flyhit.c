//flyhit.c 圣光飞翔斩
//created by foc,02-7-01
//特点说明：大威力攻击性技术。命中？自己想吧！


#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int time;
    if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
    return notify_fail("你对谁使用圣光飞翔斩？\n");
    if(!me->is_fighting())
    return notify_fail("你必须在战斗中使用这招，这招是不能用来偷袭的。\n");
    if(!me->query_temp("keearmor"))
    return notify_fail("你现在并没有处于气钢斗衣激发的状态。\n");
    if((int)me->query_skill("segokee",1)<60)
    return notify_fail("你的圣光气还没强大到足够的程度。\n");
    if((int)me->query("combat_exp")<1600000)
    return notify_fail("你尚未身经百战，别玩这个比较好。\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("你的修为还不足以使用这招。\n");
    else
{
    time=5-(int)me->query_skill("segokee",1)/50;
    message_vision(HIY "$N的气突然提高了，全身充满了杀意。身上的气钢斗衣\n自己解开了，但却并未散去！强大的力量不断集中在$N的身体之中。\n" NOR,me,target);
    me->add("force",-400);
    me->start_busy(time/2);
    call_out("flyhit", time, me, target);
}
    return 1;
}

int flyhit(object me, object target)
{
    int mysk, yoursk, myexp, yourexp, damage;
    if(!living(target) || target->is_corpse() || target->is_ghost())
    return notify_fail("现在似乎没必要用这招。\n");
    else
{
    mysk=(int)me->query_skill("segokee",1)*3 + (int)me->query_skill("force",1)+(int)me->query_skill("dodge",1);
    yoursk=(int)target->query_skill("force",1)+(int)target->query_skill("dodge",1);
    myexp=(int)me->query("combat_exp");
    yourexp=(int)target->query("combat_exp");
    damage=(mysk-yoursk/2)+(int)me->query_skill("segokee",1)*3+random(myexp/1000);
    message_vision(HIY "$N的身影突然变得模糊起来，但气却变得更加强大，充满杀意。\n$n不由的打了个冷颤。果然，$N的气钢斗衣发出奇怪的声音，\n接着气钢斗衣跟着$N以亚音速朝着$n冲了过来！\n" NOR,me,target);
   if(random(myexp)>=random(myexp/2+yourexp/3) || target->is_busy())
{
   message_vision(HIR "结果$n躲闪不及，竟然被$N就这么穿了过去！\n$N毫发无损，但鲜血却在$n的全身像玫瑰花一样盛开不息。\n" NOR,me,target);
   target->receive_damage("kee",damage);
   target->receive_damage("sen",damage);
   target->receive_wound("kee",damage);
   target->receive_wound("sen",damage);
   COMBAT_D->report_status(target,0);
   me->start_busy(random(3)+2);
   tell_object (target, "你觉得似乎自己的生命在离你而去。看着自己全身不断\n冒出来的血，你居然没有一点痛感！\n");
   tell_object (me, "对手被你这一击，精神似乎已经恍惚了。\n");
}
   else
{
   message_vision(GRN "但是$n竭尽辗转腾挪之所能，终于避了开去，却已经是满头大汗。\n" NOR,me,target);
   me->start_busy(random(3)+3);
   tell_object (target, "哇，好险！！\n");
   tell_object (me, "对手的运气不错，不过下次可能就没这么好命了。\n");
}
}
}