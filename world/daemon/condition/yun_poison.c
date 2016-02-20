// yun_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 17);
	me->receive_damage("sen", 20);
	me->apply_condition("yun_poison", duration-1);
      if( duration < 1 )
	tell_object(me, WHT "你觉得心中一片清凉，渐渐宁定下来。\n" NOR );
	else
	tell_object(me, YEL "你只觉得眼前一黑，天旋地转，登时倒了下来！\n" NOR );
	me->unconcious();
	if( duration < 1 ) 
		return 0;
	return 1;
}
