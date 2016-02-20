//steelarmor.c 气钢斗衣
//created by foc,01-7-01
//特点说明：加战斗攻防。

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target)
{
    int defence, time, str;
    if(me->query_temp("keearmor"))
    return notify_fail("你的气已经提升到了极限状态，没办法再提高了。\n");
    if((int)me->query_skill("segokee",1)<10)
    return notify_fail("你的圣光气还没强到可以实物化为铠甲的程度。\n");
    if((int)me->query("max_force")<600 || (int)me->query("force")<500)
    return notify_fail("你的气不够。\n");
    if((int)me->query("daoxing")<800000)
    return notify_fail("你的修为还不够，就算用出来了也不会有多大的效果。\n");
    if( target != me )
    return notify_fail("圣光气的防护效果无法转嫁给他人。\n");
    if(me->is_ghost())
    return notify_fail("你都已经是鬼了，还闹腾个什么呀？\n");
    else
{
    message_vision(HIY "$N大喝一声，全身的圣光气猛地放了出来。四周的空间似乎都\n扭曲了！$N继续提高自己的气，金黄色的气旋风般地往$N身\n上一裹，形成了一件金色的铠甲！\n" NOR,me);
    defence=(int)me->query_skill("segokee",1)*5;
    time=(int)me->query_skill("segokee",1)*12;
    if(defence >=200) defence=200;
    if(time >=180 ) time=180;
    me->add_temp("apply/armor", defence);
    me->add_temp("apply/armor_vs_force",defence);
    me->add_temp("apply/attack",defence*25);
    me->add_temp("apply/dodge",defence);
    me->add_temp("apply/parry",defence);
    me->add_temp("force_factor",defence);
    me->add_temp("mana_factor",defence);
    me->set_temp("keearmor",1);
    if(me->is_fighting())
    me->start_busy(3);
    me->add("force",-200);
    call_out("remove_effect",time,me);
}
    return 1;
}

void remove_effect(object me, int defence )
{
    defence=(int)me->query_skill("segokee",1)*5;
    if(defence >=200) defence=200;
    message_vision(HIY "$N身上的气钢斗衣自动解开，重新变成了气的形态，\n回到了$N的身体中。\n" NOR,me);
    me->add_temp("apply/armor",-defence);
    me->add_temp("apply/armor_vs_force",-defence);
    me->add_temp("apply/attack",-defence*25);
    me->add_temp("apply/dodge",-defence);
    me->add_temp("apply/parry",-defence);
    me->add_temp("force_factor",-defence);
    me->add_temp("mana_factor",-defence);
    me->delete_temp("keearmor");
}
