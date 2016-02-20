//kick.c 裂蹴黄斩脚
//created by foc,25-08-01
//说明：一次性小威力，命中低。

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
     int damage, myto, urto, mysk, ursk;
     if( !target ) target = offensive_target(me);
     if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
     return notify_fail("你要对谁使用「裂蹴黄斩脚」？\n");
     if(!me->is_fighting(target))
     return notify_fail("你跟他并不在战斗中。\n");
     if(me->query_temp("kick_busy"))
     return notify_fail("你刚想使用裂蹴黄斩脚，但却感到力不从心。\n");
     if((int)me->query("kee")<300)
     return notify_fail("以你现在的状况，好象不行。\n");
     if((int)me->query("force")<200 || (int)me->query("max_force")<900)
     return notify_fail("你的灵气不足以发动这招。\n");
     if((int)me->query_skill("unarmed",1)<80 || (int)me->query_skill("liejiuquan",1)<40)
     return notify_fail("以你现在的拳法修为，用不出来！\n");
     if(me->query_skill_mapped("force")!="spiritforce" && me->query_skill_mapped("force")!="segokee")
     return notify_fail("你使用的气不对。\n");
     if((int)me->query("combat_exp")<300000)
     return notify_fail("一边玩去吧，你才经历了多少战斗？\n");
     if((int)me->query("daoxing")<100000)
     return notify_fail("你的修为还不够。\n");
     else
{
mysk=(int)me->query_skill("unarmed",1)+(int)me->query_skill("liejiuquan",1)+(int)me->query_skill("force",1)+(int)me->query_skill("spiritforce",1)+(int)me->query_skill("segokee",1)*5;

ursk=(int)target->query_skill("dodge",1)*3/2+(int)target->query_skill("parry",1)*3/2;
    myto=(int)me->query("combat_exp")+mysk;
    urto=(int)target->query("combat_exp")+ursk;
    damage=mysk-ursk+random(mysk-ursk/2)+random((int)me->query("combat_exp")/5000);
    if(damage<1) damage=1;
    if((int)me->query_skill("spiritforce",1)>0)
    message_vision(HIM "$N大喝一声，强大的紫红色灵气立刻从\n身上释放出来，集中在$N的右脚之上。\n" NOR,me,target);
    if((int)me->query_skill("segokee",1)>0)
    message_vision(HIY "$N的全身放出金黄色的圣光气，强大的\n气很快在$N的右脚上聚集起来。\n" NOR,me,target);
    message_vision(GRN "$N临空跃起，使出了灵光裂蹴拳的绝技：\n"+BLINK""+HIY"裂蹴黄斩脚"NOR"，$n立刻感到了其攻势的强大！\n" NOR,me,target);
{
    me->add("force",-300);
    me->start_busy(1+random(2));
    me->set_temp("kick_busy",1);
    call_out("remove_effect",10+random(5),me);
    if(random(myto)>=random(myto/2+urto/2) || target->is_busy())
{
    message_vision(GRN "结果$n躲闪不及，被$N用腿踢了个正着！\n" NOR,me,target);
    target->receive_damage("kee",damage);
    target->receive_damage("sen",damage);
    target->receive_wound("kee",damage/2);
    target->receive_wound("sen",damage/2);
    COMBAT_D->report_status(target,0);
    COMBAT_D->report_sen_status(target);
}
    else message_vision(GRN "但是$n避开了$N的攻击。\n" NOR,me,target);
}
}
    target->kill_ob(me);
    me->kill_ob(target);
    return 1;
}
void remove_effect(object me)
{
  if (!me) return;
  me->delete_temp("kick_busy");
}
