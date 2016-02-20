//By angela@mhxy 2001.12.29
// jingheal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("eff_sen") < (int)me->query("max_sen") / 2 )
		return notify_fail("你精神实在不济，只怕一运内功便有生命危险！\n");

message_vision(
HIW "$N坐了下来运起白云心法，过了不久，$N脸上亮出晶莹的颜色，缓缓睁开的眼里透出青春的气息。\n" NOR,
	me );

	me->receive_curing("sen", 10 + (int)me->query_skill("spells")/2 );
	me->add("force", -30);

	return 1;
}
