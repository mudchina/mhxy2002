
#include <ansi.h>
#include "/u/tianlin/eff_msg.h";
void remove_effect(object me);

inherit SSERVER;
int perform(object me, object target)
{
	object weapon;
	int skill;
	string msg;
	if( !me->is_fighting() ) 
		return notify_fail("［借力打力］只能在战斗中使用。\n");
	if( target != me ) 
		return	notify_fail("你只能将［借力打力］用在自己的身上。\n");

	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你先要放下手中的武器。\n");
	if(me->query("family/family_name") != "武当派")
           return notify_fail("你不是武当派的弟子，不能使用绝招！\n");

	if( (int)me->query_skill("taiji-quan", 1) < 100 )
		return notify_fail("你的太极拳不够娴熟，不会使用「借力打力」。\n");
	if( (int)me->query_skill("wudang-force", 1) < 100 )
		return notify_fail("你的太级神功不够娴熟，不会使用「借力打力」。\n");
	if( (int)me->query("int") < 20 )
		return notify_fail("你的才智太低了，领悟不了「借力打力」。\n");

	if( (int)me->query("force") < 200  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query_temp("tjj_jie") ) 
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("taiji-quan",1);
	message_vision(HIR "$N使出太极拳法的精髓，护住自己周身各大要穴，并试着破解对方招式。\n"NOR,me);

	me->set_temp("tjj_jie", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me:), skill/5);

	me->add("neili", -200);
	me->start_busy(3);

	return 1;
}

void remove_effect(object me)
{
	me->delete_temp("tjj_jie");
	tell_object(me, HIY "你的[借力打力]运行完毕，功效失灵了。\n"NOR);
}
