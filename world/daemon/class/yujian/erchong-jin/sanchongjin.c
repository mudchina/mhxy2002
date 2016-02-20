// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        //extra = me->query_skill("zanglong-force",120);
        //if ( extra < 100) return notify_fail("你的［藏龙心法］还不够纯熟！\n");
        //dodskill = (string) me->query_skill_mapped("force");
        //if ( dodskill != "zanglong-force")
        //                return notify_fail("［三重劲］需要［藏龙心法］的配和！\n");
        //tmp = me->query_skill("erchong-jin",120);
        //if ( tmp < 50 )return notify_fail("你的［二重劲］还不够纯熟！\n");
        if((int)me->query("max_force") < 1500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
             
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［三重劲］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIC"$N双手握拳,飞身上前,一拳打向$n!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"$N紧接一拳,打向第一击打的地方,$n大叫了一声!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"$N又是一拳,继续打向前两拳打的地方,$n被打的跪倒在地!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->start_busy(2);
        me->receive_damage("kee", 100);
        
        me->add("force", -400);


        me->start_busy(3);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}