// piao
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("piaoxiang",1);
	if ( extra < 100) return notify_fail("你的［"HIR"血海飘香"NOR"］还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［"HIR"血海飘香"NOR"］只能对战斗中的对手使用。\n");
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision(HIR"$N脚踏八方，身行如血海之中飘过一丝血腥，飘渺不定！\n"NOR,me,target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
	message_vision(HIW"结果$N被扰得眼花潦乱，接应不暇！\n"NOR,target);
        target->start_busy(1);
     }
        else{
	msg = ""HIW"可惜$N看出了$n的身法，向你迅然攻击！"NOR"";
	COMBAT_D->do_attack(target,me, target->query_temp("weapon"),TYPE_REGULAR,msg);	
	}
	return 1;
}
