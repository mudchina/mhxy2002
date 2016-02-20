// pozhan.c 		破绽百出

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int delay, myblade;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("不在战斗中，露什么破绽？\n");

	myblade=(int)me->query_skill("kugu-blade",1);
	if(myblade>160) myblade=160; // mon 12/7/98
	if(myblade<50) 
		return notify_fail("你的修为不够深，露破绽给人太危险了。\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

	msg = CYN "$N的招式突然一变，变得全无章法，浑身上下破绽百出，\n";

    if( random(me->query("combat_exp")) >( ((int)target->query("combat_exp")/3) )) {
		msg += "$n想攻，却不知道哪个破绽是真，哪个是假。\n";
		msg += "结果$p被$P攻了个措手不及！\n" NOR;
       delay = random(myblade/32)+myblade/32;
		target->start_busy(delay);
	} else {
		msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
      delay = random(myblade/24);
              me->start_busy(2+random(1));
	}
	message_vision(msg, me, target);

	return 1;
}
