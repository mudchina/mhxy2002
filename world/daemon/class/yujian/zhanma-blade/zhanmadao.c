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
        extra = me->query_skill("zhanma-blade",130);
        if ( extra < 100) return notify_fail("你的［斩马刀］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("blade");
        if ( dodskill != "zhanma-blade")
                        return notify_fail("［斩马刀］需要［斩马刀］的配和！\n");
        tmp = me->query_skill("zhanma-blade",130);
        if ( tmp < 50 )return notify_fail("你的［斩马刀］还不够纯熟！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［斩马刀］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIC"$N使出斩马刀中的三连斩！\n\n\n$N手中"+weapon->query("name")+HIW"闪电般的向$n挥出第一刀!\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"$N手中"+weapon->query("name")+HIW"向$n挥出第二刀！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW"$N手中"+weapon->query("name")+HIW"向$n挥出第三刀！\n\n"NOR,me, target);
        target->start_busy(2);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->receive_damage("kee", 100);
        
        me->add("force", -400);


        me->start_busy(4);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}