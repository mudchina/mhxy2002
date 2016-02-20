//by tianlin 2001.7.30
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
                return notify_fail("你要对谁施展这一招「咄咄逼人」？\n");

        if(!me->is_fighting())
                return notify_fail("「咄咄逼人」只能在战斗中使用！\n");

          if(me->query("family/family_name") != "天蓬帅府" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("kee") < 500 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

          if((int)me->query_skill("tianpeng-zhang", 1) < 100)
                  return notify_fail("你的天蓬掌法级别还不够，使用不出来！\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	if (! present(target,environment(me))) return 1;
        message_vision(HIC"$N双手握拳,飞身上前,一拳打向$n!\n\n"NOR,me, target);
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIC"$N紧接一拳,打向第一击打的地方,$n大叫了一声!\n\n"NOR,me, target);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIC"$N又是一拳,继续打向前两拳打的地方,$n被打的跪倒在地!\n\n"NOR,me, target);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");
        target->start_busy(1);

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}

