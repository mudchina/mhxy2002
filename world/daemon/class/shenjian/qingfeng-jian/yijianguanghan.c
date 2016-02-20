// LLY@FYSY
//百分之百的婊子招,切忌千万不要使用
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("qingfeng-jian",1);
	if ( extra < 50) return notify_fail("你的［清风细雨温柔剑］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［一剑光寒］只能对战斗中的对手使用。\n");
	message_vision(HIB "$N一剑刺出，接着对$n说到：“我这一剑，势在必中，若是不中，再多千百剑也是没用的。”\n" NOR,me,target);
	if(random((int)target->query("combat_exp")) > (int)me->query("combat_exp"))
	{
	msg = HIW "一道寒光从$n身上穿过。\n" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);	
        
        me->start_busy(1);
        return 1;
        }
	else
        {
	msg = "$n见势不好，飞身跃开...\n";
        message_vision(msg,me,target);
	me->start_busy(0);
        return 1;
	}
	return 1;
}
