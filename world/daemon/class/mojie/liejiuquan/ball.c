//ball.c 裂踢红球波
//created by foc,25-08-01
//说明：大威力灵气攻击。

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
     int damage, myto, urto, mysk, ursk, n;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("你要对谁使用「裂踢红球波」？\n");
     if((int)me->query("kee")<200)
     return notify_fail("以你现在的状况，灵气放出太多会隔屁的。\n");
     if((int)me->query("force")<300 || (int)me->query("max_force")<1400)
     return notify_fail("你的灵气不足以发动这招。\n");
     if((int)me->query_skill("unarmed",1)<110 || (int)me->query_skill("liejiuquan",1)<50)
     return notify_fail("以你现在的拳法修为，别玩啦！\n");
     if(me->query_skill_mapped("force")!="spiritforce"||me->query_skill_mapped("force")!="segokee")
     return notify_fail("你使用的气不对。\n");
     if((int)me->query("combat_exp")<200000)
     return notify_fail("一边玩去吧，你才经历了多少战斗？\n");
     if((int)me->query("daoxing")<200000)
     return notify_fail("你的修为还不够。\n");
     else
{
     mysk=(int)me->query_skill("unarmed",1)+(int)me->query_skill("liejiuquan",1)+(int)me->query_skill("force",1)+(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*5;
ursk=(int)target->query_skill("dodge",1)*3/2+(int)target->query_skill("parry",1)*3/2;
    myto=(int)me->query("combat_exp")+mysk;
    urto=(int)target->query("combat_exp")+ursk;
    damage=mysk-ursk+random(mysk-ursk/2);
    if(damage<1) damage=1;
    if((string)me->query_mapped_skill("force")=="spiritforce")
    message_vision(HIM "$N的右手一抬，强大的紫红色灵气立刻在手中聚集成一个能量球。\n" NOR,me,target);
    if((string)me->query_mapped_skill("force")=="segokee")
    message_vision(HIY "$N的全身放出金黄色的圣光气，强大的气很快在\n$N的右手手中聚集成一个光芒四射的能量球。\n" NOR,me,target);
    message_vision(HIW "只见$N将那能量球临空一抛，接着飞身而上，右脚以雷\n霆万钧之势踢在球上。那球带着旋转的气流犹如彗星般袭向$n！\n" NOR,me,target);
{
    me->add("force",-300);
    me->set_temp("ball_busy",1);
    me->start_busy(3);
    if(random(myto)>=random(myto/2+urto/2) || target->is_busy())
{
    message_vision(GRN "结果$n躲闪不及，被那能量球击中。\n整个人横飞而开，在空中留下一道长长的"+BLINK""+HIR"血迹"NOR"！\n" NOR,me,target);
    target->receive_damage("kee",damage);
    target->receive_damage("sen",damage); 
    target->receive_wound("kee",damage/3*2);
    target->receive_wound("sen",damage/3*2);
    COMBAT_D->report_status(target,0);
    COMBAT_D->report_sen_status(target);
    me->start_busy(2+random(2));
}
    else
{
    n=(int)target->query("kar")*2;
    if(n<50 && n>=40 )
    message_vision(GRN "但是$n轻轻一闪，躲了过去，没有受到任何伤害。\n" NOR,me,target);
    if(n<40 && n>=30 )
{
    message_vision(GRN "但是$n情急生智，使个铁板桥，总算\n避了开去，不过好象受了一点点小伤。\n" NOR,me,target);
    target->receive_damage("kee",100);
    target->receive_wound("kee",5);
}
    if(n<30 && n>=10)
{
    message_vision(GRN "但是$n拼出全力，将$N的灵气球引向了一边。\n" NOR,me,target);
    me->command("kao");
    target->add("force",-50);
}
    else
{
    message_vision(GRN "但是$n拼出老命，总算挡住了这一击，\n也没有受伤，不过全身却是一片酸痛。\n" NOR,me,target);
    target->start_busy(2);
}
}
}
}
    return 1;
}

void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("ball_busy");
}
