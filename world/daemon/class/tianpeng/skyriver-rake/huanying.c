//huanying.c by yushu 2001/6
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int delay,mydodge,mebusy;
	object weapon;
	mydodge = me->query_skill("chaos-steps",1);
       if(mydodge>100) mydodge=100;
	delay=mydodge/18;
	if ( mydodge < 50) return notify_fail("你的「倒乱七星步法」还不够纯熟！\n");
       if(me->query_temp("no_huanying")) return notify_fail("绝招滥使就不灵了！\n");
       if((int)me->query("force") < 200 ) return notify_fail("你的内力不足！\n");
       if((int)me->query("sen") < 200 ) return notify_fail("你的精神不足，没法子施用外功！\n");
       if((int)me->query("max_force") < 200 ) return notify_fail("你的内力不够！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「移形幻影」只能对战斗中的对手使用。\n");
	if(target->is_busy()) return notify_fail(target->name()+"已经手忙脚乱了！\n");
	message_vision(HIW"$N身形骤然加快，一化十，十化百，百化千，化出千千万万的人影把$n围在中间。\n"NOR,me,target);
	if( ((random(me->query("combat_exp"))*3/4 + (me->query("combat_exp")/4) > (int)target->query("combat_exp")*5/8 )))
	{
	message_vision(HIG"结果$N被扰得眼花潦乱，接应不暇！\n"NOR,target);
	target->start_busy(delay);
	} else {
	message_vision(HIR"可惜$N看出了$n的身法，向你迅然攻击！\n"NOR,me,target);
	COMBAT_D->do_attack(target,me,target->query_temp("weapon"));
       if ( mydodge > 100 ) mebusy=2;
       if ( mydodge > 150 ) mebusy=3;
       if ( mydodge > 180 ) mebusy=4;
       if ( mydodge > 200 ) mebusy=5;	
       me->start_busy(mebusy);
	}
       me->receive_damage("sen", 200);
       me->add("force",-200);
       me->set_temp("no_huanying",1);
	call_out("huanying_ok",5,me);
	return 1;
}

void huanying_ok(object me)
{ if (!me) return;
      me->delete_temp("no_huanying");
}         
