// LLY@FYSY
//By tianlin@mhxy for 2001.11.27.修改成XYJ版本
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt;
	object weapon;
	extra = me->query_skill("duo-sword",1);
	if ( extra < 110) return notify_fail("你的夺命连环剑法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("你要对谁使用这一招"HIY"((夺命十三式))。\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <110)
return notify_fail("你的心法还不够纯熟！\n");
	 msg = HIR  "$N轻描淡写，挥尘如意，一瞬间就已使出夺命十三式，手中的"+ weapon->name()+  NOR+HIR"轻灵流动.\n就像是河水般的向$n刺出,天地间彷佛充满了杀气！\n\n" NOR;
        message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/10);
	me->add_temp("apply/damage",extra/10);
	lmt = random(13)+1;
	for(i=1;i<=lmt;i++)
	{
message_vision(BLINK HIR"------>>>>>>第"HIC+chinese_number(i)+HIR"剑<<<<<<------"NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        msg = CYN "\n\n$N的第"+chinese_number(i-1)+"剑刺出后，所有的变化都已穷尽，又像是流水已到尽头，剑势也慢了，很慢。\n\n"NOR;
	message_vision(msg,me,target);
        me->add_temp("apply/attack",-extra/10);
        me->add_temp("apply/damage",-extra/10);
	me->start_busy(2);
	return 1;
}
