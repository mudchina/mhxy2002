
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


void remove_effect(object me, int a_amount, int d_amount);

inherit SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target

        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「无敌风火轮」只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "spear")
                return notify_fail("「无敌风火轮」必须用枪才能施展。\n");

             if( (int)me->query_skill("huoyun-qiang", 1) < 100 )
                return notify_fail("你的「火云枪」不够娴熟，不会使用「无敌风火轮
」。\n");

        if( (int)me->query("force") < 500  )
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("huoyun-qiang");
        msg = HIG "$N枪头一挑，手中的兵器分出无数影子，顿显杀气。\n"NOR;
        message_vision(msg, me, target);

        me->add("force", -100);


        msg = HIR"【无字诀】！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        msg = HIY"【敌字诀】！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        msg = HIG"【风字诀】！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        msg = HIR"【火字诀】！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        msg = HIW"【轮字诀】！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);


        me->start_busy(3);

        return 1;
}
