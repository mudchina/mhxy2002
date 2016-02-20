// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
      int sec, min, hrs, day, mon, age;
         
                age = (int)me->query("mud_age");                
                sec = age % 60;
                age /= 60;
                min = age % 60;
                age /= 60;
                hrs = age % 24;
                age /= 24;
                day = age % 30;

	if(day == 0 && ! me->query("birth_yn")) 
	{ 
		tell_object(me, BLINK HIW "你的生日到了，快去人间仙境领自己的生日礼物吧！\n" NOR );
		me->set("birth_yn",1);
//		me->set("birth_notice",1);
        }		
	me->apply_condition("birthday", 10);
	return 1;
}
