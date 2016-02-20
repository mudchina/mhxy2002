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
        extra = me->query_skill("kugu-blade",100);
        if ( extra < 100) return notify_fail("你的［枯骨刀］还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("sword");
        if ( dodskill != "qixiu-jian")
                        return notify_fail("［计出连环］需要［七修剑］的配和！\n");
        tmp = me->query_skill("qixiu-jian",100);
        if ( tmp < 50 )return notify_fail("你的［七修剑］还不够纯熟！\n");
        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［计出连环］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(CYN  "\n\n$N挥出枯骨刀中的绝天灭地的一式－－－计－出－连－环－！！\n\n\n论战篇！\n$N手中"+weapon->name()+"直劈你的敌人！" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "胜战篇！\n$N手中"+weapon->name()+"斜刺你的敌人！" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "混战篇！\n$N手中"+weapon->name()+"狠剁你的敌人！" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "决战篇！\n$N手中"+weapon->name()+"加紧，旋风般向你的敌人杀去！" NOR, me, weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->start_busy(1+random(2));
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}
