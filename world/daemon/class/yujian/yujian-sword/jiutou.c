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
        extra = me->query_skill("zanglong-force",200);
        if ( extra < 100) return notify_fail("你的［藏龙心法］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "suodi-steps")
                        return notify_fail("［九头龙闪］需要［缩地］的配和！\n");
        tmp = me->query_skill("yujian-sword",240);
        if ( tmp < 50 )return notify_fail("你的［飞天御剑剑法］还不够纯熟！\n");
        if((int)me->query("max_force") < 2400 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1600 )
             
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 350 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［九头龙闪］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIR"$N挥出飞天御剑流中的一式－－－九头龙闪！！\n\n\n$N手握"+weapon->query("name")+HIR"用出一招［唐竹］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(BLK"$N手握"+weapon->query("name")+BLK"用处一招［袈裟斩］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(GRN"$N手握"+weapon->query("name")+GRN"用处一招［逆袈裟］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(BLU"$N手握"+weapon->query("name")+BLU"用处一招［左雉］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"$N手握"+weapon->query("name")+WHT"用处一招［右雉］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIG"$N手握"+weapon->query("name")+HIG"用处一招［左切上］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(MAG"$N手握"+weapon->query("name")+MAG"用处一招［右切上］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"$N手握"+weapon->query("name")+HIC"用处一招［逆风］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"$N手握"+weapon->query("name")+HIB"用处一招［刺突］向$n打去！\n\n"NOR,me, target);
        target->start_busy(5);
        COMBAT_D->do_attack(me,target,  me->query_temp("weapon"),TYPE_REGULAR,msg);me->receive_damage("kee", 100);
        
        me->add("force", -1200);
        
        me->start_busy(4);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}