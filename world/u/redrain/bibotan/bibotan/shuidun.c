//cast function: escape.c 可用于各种逃遁。

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	int ap, dp, success;
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( me->is_busy())
		return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("你精神太差，难以集中精力念咒。\n");

	if( (int)me->query_skill("bihai-spells", 1) < 30)
		return notify_fail("你未曾学会水遁。\n");

	ap=me->query_skill("spells")+me->query("max_mana")/10;
	if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

	if(!me->is_fighting() )
	{
		message_vision(HIY"$N念了几句咒语，身下涌起一波水花，$N借着水花不见了。\n"NOR,me);
		me->add("sen", -me->query("max_sen")/8);
		me->add("mana", -80);
		success=1;
	}
	else
	{
		msg=HIY"$N眼见不敌，突然跳出战圈，念了几句咒语...\n"NOR;
		if(random(ap+dp)>dp/2)
		{
			msg+=HIY"接着白光一闪,$N的身影已经不见了。\n"NOR;
			me->add("sen", -me->query("max_sen")/6);
			me->add("mana", -50);
			success=1;
		}
		else msg+=HIY"但$n的身影已紧紧跟上，将$N拦了下来。\n"NOR;
		me->add("mana", -50);
		message_vision(msg, me, target);
	}
	if(success)
	{
		if(!start) start/d/qujing/bibotan/yujie.c";
		me->move(start);
		message("vision", HIY+me->name()+"伴着一波水花出现在你的面前。\n"NOR,
				  environment(me), me);
		tell_object(me, HIY"你的身影突然出现在一波水花中。\n"NOR);
		return 3+random(3);
	}
	return 5+random(5);
}

