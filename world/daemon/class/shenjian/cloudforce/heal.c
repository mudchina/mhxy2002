//By angela@mhxy 2001.12.29
// heal.c

#include <ansi.h>

int exert(object me, object target)
{
	if( me->is_fighting() )
		return notify_fail("战斗中运功疗伤？找死吗？\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("你的真气不够。\n");

	if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
		return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");

	message_vision(
	HIW"$N坐了下来运起白云心法，呼吸吐纳，身边升起缭绕的白雾。\n" NOR, me );

	me->receive_curing("kee", 10 + (int)me->query_skill("force")/2 );
	me->add("force", -30);

	return 1;
}
