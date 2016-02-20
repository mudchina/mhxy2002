#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［迷踪幻影连环脚］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("lianhuan-zhang",1) / 10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "$N施展出［迷踪幻影连环脚］，身形极度旋转，一丛人影中突然向$n飞出一腿！" NOR;
	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "人影中又飞出一腿！" NOR;
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N身形渐稳，反身又是一腿！" NOR;
        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"瘀伤");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}
