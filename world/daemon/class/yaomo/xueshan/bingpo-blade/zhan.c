#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「春风快意斩」？\n");

        if(!me->is_fighting())
                return notify_fail("「春风快意斩」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

	if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("春风快意斩必须配合冰谷凝血功才能使用。\n");
  if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("bingpo-blade", 1) < 100)
                return notify_fail("你的冰魄刀级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIC"\n$N屏气凝视对方的破绽，身形急转，霹雳间连续奋不顾身的向$n一口气连出数招！\n"NOR,me,target);

        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

 
me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

 
me->set_temp("QJB_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

         me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}

