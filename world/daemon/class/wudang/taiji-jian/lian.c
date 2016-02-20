//By tianlin@mhxy for 2001.9.30

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("太极剑法"BLINK+HIR"「连」"NOR"字诀只能对战斗中的对手使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

	if( (int)me->query_skill("taiji-jian", 1) < 50 )
		return notify_fail("你的太极剑法不够娴熟，不能用「连」字诀。\n");

	if( (int)me->query_skill("wudang-force", 1) < 60 )
		return notify_fail("你的武当内功不够娴熟，不能使用「连」字诀。\n");

	extra = me->query_skill("taiji-jian",1) / 20;
	extra += me->query_skill("wudang-force",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	message_vision(HIR"$N运起［太极神功］，同时使出"HIY"［太极剑法中］"NOR+HIR"的"NOR+BLINK+HIR"「连」"NOR+HIR"字诀，手中的"+ weapon->name() +" 一招连着一招画起圈来，闪电般的击向$n！"NOR,me,target);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  BLINK HIC "剑光一闪，消失．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	message_vision(HBRED HIW"$N用剑画了一个圈，一剑又连了上来！\n" NOR,me,target);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->add("force", -100);
	me->start_busy(3);
	return 1;
}

