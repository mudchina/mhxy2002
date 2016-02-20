//By tianlin@mhxy for 2001.12.5部分优化
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("qingfeng-jian",1);
	if ( extra < 120) return notify_fail("你的清风细雨温柔剑还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(""HIR"［"HIW"剑气纵横"HIR"］"NOR"只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	message_vision(HIW"$N手中的"NOR+ weapon->name()+ HIW "一出鞘，就化做一道光华击向$n"HIW"，一道弧形的光华：灿烂、辉煌、美丽。\n" + HIG"光华在闪动、变幻、高高在上，轻云飘忽，$n"HIG"只觉得这道光华彷佛就在自己眉睫
间，却又不能确定它在那里？它的变化，几乎已超越了人类能力的极限，几乎已令人无法置信。"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(HIY"可是它确实在那里，而且无处不在。可是就在$n"HIY"已确定它存在时，它忽然又不见
了。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	message_vision(WHT"又奇迹般忽然出现，又奇迹般忽然消失。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(HIR"所有的动作和变化，都已在一刹那间完成，终止。就像是流星，却又像是闪电，却又比
流星和闪电更接近奇迹。因为催动这变化的力量，是由$N发出来的。"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       target->start_busy(1+random(2));
	me->start_busy(1+random(2));
	return 1;
}
