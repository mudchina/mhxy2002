// lifeheal.c

#include <ansi.h>

int exert(object me, object target)
{

	if ( !target
      ||      !userp(target)
      ||      target->is_corpse()
      ||      target==me)
		return notify_fail("你要替谁解毒？\n");
	if (!target->query_condition("xiangsi"))
        return notify_fail("他根本不需要你的帮助！\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("战斗中无法运功疗伤！\n");

	if( (int)me->query("force") - (int)me->query("max_force") <  600 )
		return notify_fail("你的真气不够。\n");

    if ((int)me->query_skill("moonforce",1)<80)
		return notify_fail("你的内功修为不足以替人解除相思之苦。\n");
	
	message_vision(
		HIY "$N坐下来将$n默默的拦入怀中，$n感受$N爱人般的温暖，思念之情默默平复。\n\n"NOR,
		me, target );
    if (random(me->query_skill("moonforce", 1)-60)>10){
		target->apply_condition("xiangsi",0);
		message_vision(
		HIY "$N唱起了宁和的歌曲，$n心中既感激，又安慰，在那温柔的歌声中慢慢进入了睡乡。\n"NOR,
		me, target );
		target->set_temp("force_sleep",1);
		target->command_function("sleep");

		target->delete_temp("force_sleep");	}
	else {
		message_vision(
		HIY "$N突然脸色苍白，似乎心力有所不及，竟呕出一口血来……\n"NOR,
		 me, target );
	}	
 
	target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -150);
	me->set("force_factor", 0);
	return 1;
}
