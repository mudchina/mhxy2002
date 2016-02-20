// yingzhaogong.c 牧野鹰扬
// By tianlin 2001.5.1
#include <ansi.h>

inherit SSERVER;
string msg;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

/*	if((int)me->query_str() < 30)
		return notify_fail("你臂力不够,不能使用牧野鹰扬！\n");
*/
	if((int)me->query_skill("ningxie-force",1) < 100)
		return notify_fail("你冰谷凝血功的功力不够，不能使用牧野鹰扬！\n");

	if((int)me->query_skill("yingzhaogong",1) < 100)
		return notify_fail("你的鹰爪功功修为不够,目前还不能使用牧野鹰扬！\n");

	if((int)me->query("force") < 800)
		return notify_fail("你内力现在不够, 不能使用牧野鹰扬！\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧!\n");

	msg = HIY "$N使出鹰爪功绝技「牧野鹰扬」，双爪蓦地抓向$n的全身要穴。\n";

	if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 4 ) {
		msg += "结果$p被$P攻了个措手不及，立时动弹不得！\n" NOR;
		target->start_busy( (int)me->query_skill("yingzhaogong",1) / 10 + 2);
		me->add("force", -150);
	} else {
		msg += HIG "可是$p看破了$P的企图，并没有上当。\n" NOR;
		me->start_busy(4);
	}
	message_vision(msg, me, target);

	return 1;
}
