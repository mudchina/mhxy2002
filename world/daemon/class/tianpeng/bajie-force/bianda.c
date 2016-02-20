//by valen 2001.7.28
//add by tianlin.简直就是狗屁不通,还好意思by valen.真shit

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("bajie-force",1);

	if( skill > 250 ) {
		skill=250;
	}

        if( target != me ) 
		return notify_fail("变大法只能给自己使用。\n");

        if( (int)me->query("force") < skill*2 )     
		return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
		return notify_fail("你已经变大了。\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIC "$N猛吸一口气，运起八戒心法，全身闪起点点"BLINK+HIY"金光"NOR+HIC"，只见$N的身体慢慢的变大了!\n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
	me->add_temp("apply/strength", - amount);
        me->delete_temp("powerup");
        me->add("bellicosity", amount*2 );
	// mon 3/1/98. move this to after powerup is done.
        tell_object(me, HIB"$N的八戒心法运行一周天完毕，接着身体变了回来。\n"NOR);
}

