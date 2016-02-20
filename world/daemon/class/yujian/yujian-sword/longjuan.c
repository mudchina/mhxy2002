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
        extra = me->query_skill("zanglong-force",130);
        if ( extra < 100) return notify_fail("你的［藏龙心法］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("sword");
        if ( dodskill != "yujian-sword")
                        return notify_fail("［奥义·龙卷闪］需要［飞天御剑剑法］的配和！\n");
        tmp = me->query_skill("yujian-sword",130);
        if ( tmp < 50 )return notify_fail("你的［飞天御剑剑法］还不够纯熟！\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 600 )
             
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［奥义·龙卷闪］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIC"$N挥出飞天御剑流中的一式－－－奥义·龙卷闪！！\n\n\n$N手中"+weapon->query("name")+HIW"直劈$n！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N手中"+weapon->query("name")+HIW"斜刺$n！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"$N手中"+weapon->query("name")+HIW"狠剁$n！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW"$N手中"+weapon->query("name")+HIW"加紧，旋风般向$n杀去！\n\n"NOR,me, target);
        target->start_busy(2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->receive_damage("kee", 100);
        
        me->add("force", -600);


        me->start_busy(3);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}