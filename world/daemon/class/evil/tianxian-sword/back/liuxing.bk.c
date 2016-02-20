// ken xyj
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,i,lmt;
        object weapon;
        extra = me->query_skill("tianxian-sword",1);
        if ( extra < 90) return notify_fail("你的天仙剑法根本还没练好，岂能用得出来？\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("这可不是闹着玩的.\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力还不足发流星。\n");

        if((int)me->query("force") < 700 )
                return notify_fail("你的内力不够用，怎么发也出不了流星！\n");

        weapon = me->query_temp("weapon");
        msg = HIY  "$N运力一震手中的"+ weapon->name()+  "顿时抖出无数的流星，狂风暴雨般地向$n扫来！" NOR;
        message_vision(msg,me,target);
        me->add_temp("apply/attack",extra/10);
        me->add_temp("apply/damage",extra/10);
        lmt = random(3)+3;
        for(i=1;i<=lmt;i++)
        {
        msg =  HIR "第"+chinese_number(i)+"剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
        me->start_busy(3);
        return 1;
}
