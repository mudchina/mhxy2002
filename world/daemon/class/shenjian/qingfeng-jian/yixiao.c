//By tianlin@mhxy for 2001.12.5部分优化
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
        int extra1;
	object weapon;
        extra1 = me->query_skill("qingfeng-jian",1);
	if ( extra1 < 60) return notify_fail("你的［清风细雨温柔剑］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(""HIR"［"HIC"剑神一笑"HIR"］"NOR"只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("sword") / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	message_vision(HBRED+HIW  "$N"HBRED+HIW"手中"NOR+HBBLU+HIY+ weapon->name() +NOR+HBRED+HIW"的剑芒向$n"HBRED+HIW"散发出若有若无的浅笑．．．"NOR,me,target);
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(1);
	return 1;
}
