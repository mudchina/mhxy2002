//ziyandan.c 紫炎弹
//created by foc,25-08-01
//说明：超大威力灵气攻击。

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
     int damage, myto, urto, mysk, ursk, n1;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("你要对谁使用「紫炎弹」？\n");
     if((int)me->query("kee")<300)
     return notify_fail("以你现在的状况，灵气放出太多会隔屁的。\n");
     if((int)me->query("force")<400 || (int)me->query("max_force")<1500)
     return notify_fail("你的灵气不足以发动这招。\n");
     if((int)me->query_skill("unarmed",1)<160 || (int)me->query_skill("liejiuquan",1)<100)
     return notify_fail("以你现在的拳法修为，用不出来！\n");
     if(me->query_skill_mapped("force")!="spiritforce" && me->query_skill_mapped("force")!="segokee")
     return notify_fail("你使用的气不对。\n");
     if((int)me->query("combat_exp")<800000)
     return notify_fail("一边玩去吧，你才经历了多少战斗？\n");
     if((int)me->query("daoxing")<400000)
     return notify_fail("你的修为还不够。\n");
     else
{
     mysk=(int)me->query_skill("unarmed",1)+(int)me->query_skill("liejiuquan",1)+(int)me->query_skill("force",1)+(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*5;

ursk=(int)target->query_skill("dodge",1)*3/2+(int)target->query_skill("parry",1)*3/2;
    myto=(int)me->query("combat_exp")+mysk;
    urto=(int)target->query("combat_exp")+ursk;
    damage=mysk-ursk/3*2+random(mysk-ursk/2)+random((int)me->query("combat_exp")/5000);
    if(damage<1) damage=1;
    if((int)me->query_skill("spiritforce",1)>0)
    message_vision(HIM "$N双手一展，强大的紫红色灵气立刻从身上\n释放出来，形成了无数的紫红色能量球。\n" NOR,me,target);
    if((int)me->query_skill("segokee",1)>0)
    message_vision(HIY "$N的全身放出金黄色的圣光气，强大的气很快在\n$N的四周聚集成无数光芒四射的能量球。\n" NOR,me,target);
    message_vision(HIW "$N大喝一声，所有的能量球集中起来，接着右脚以雷霆万钧之势踢\n在那些球上。所有能量球球带着旋转的气流犹如流星般射向$n！\n" NOR,me,target);
{
    me->add("force",-600);
    me->start_busy(3+random(3));
    me->set_temp("ZY_busy",1);
    call_out("remove_effect",30+random(5),me);
    if(random(myto)>=random(myto/3+urto/2) || target->is_busy())
{
    n1=(int)me->query_skill("liejiuquan",1)*3+random((int)me->query_skill("liejiuquan",1));
    message_vision(GRN "结果$n躲闪不及，全身上下共中了"+chinese_number(n1)+"处攻击。\n整个人横飞而开，在空中留下无数长长的"+BLINK""+HIR"血迹"NOR"！\n" NOR,me,target);
    target->receive_damage("kee",damage*n1/5000);
    target->receive_damage("sen",damage*n1/5000); 
    target->receive_wound("kee",damage*n1/2000);
    target->receive_wound("sen",damage*n1/2000);
    COMBAT_D->report_status(target,0);
    COMBAT_D->report_sen_status(target);
}
    else message_vision(GRN "但是$n一个纵身，极尽辗转腾挪之能，总算躲了过去。\n" NOR,me,target);
}
}
    message_vision(GRN "$n指着$N大骂：好你个臭贼，敢出阴招！\n" NOR,me,target);
    target->kill_ob(me);
    me->kill_ob(target);
    return 1;
}

void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("ZY_busy");
}
