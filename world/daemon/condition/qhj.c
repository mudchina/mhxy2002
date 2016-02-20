// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("kee", 45);
	me->receive_damage("sen", 50);
	me->apply_condition("qhj", duration - 1);
        if( duration < 1 )
	tell_object(me, HIW "你中的" HIC "氰化钾" HIW "毒终于清除了！\n" NOR );
	else
	tell_object(me, HIW "你中的" HIC "氰化钾" HIW "毒发作了！\n" NOR );
	if( duration < 1 ) 
		return 0;
	return 1;
}
