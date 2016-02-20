// wuji-force.c  【无极心法】 created 17-06-2001 piao

#include <ansi.h>

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("无极心法只能向师父学，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("youxia") + "/wuji-force/" + func;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else if ( level < 290 ) return 8;
       else if ( level < 360 ) return 9;
       else if ( level < 420 ) return 10;
       else if ( level < 499 ) return 11;
       else return 12;
}

string level_description(int level)
{
	if ( stage(level) < 3 )
		return BLU "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 5 )
		return HIB "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 7 )
		return YEL "第"+chinese_number( stage(level) )+"重　" NOR;
	else if ( stage(level) < 9 )
		return CYN "第"+chinese_number( stage(level) )+"重　" NOR;
       else if ( stage(level) < 11)
		return HIC "第"+chinese_number( stage(level) )+"重" NOR;
       else 
		return HIW "第"+chinese_number( stage(level) )+"重" NOR;
}

void skill_improved(object me)
{
	//if stage increased, give bonus...?
	int level = (int)me->query_skill("ningxie-force", 1);
	if ( stage(level) == stage(level-1) + 1)
	{
		//this is to prevent ppls from abondoning skill to get bonus.
		if( (int)me->query("nx-force_bonus") < stage(level) )
		{
			me->set("nx-force_bonus", stage(level));
//			me->set("max_force", (int)me->query("max_force") + stage(level)*50 );
			// mon 12/13/98
			me->set("maximum_force", 
				(int)me->query("maximum_force") 
				+ stage(level)*50 );
			me->save();
			log_file("ningxie-force-bonus", ctime( time() )+": "
				+me->query("name")+"("+me->query("id")+")"
				+" got neili "+(stage(level)*50)+".\n");
			message_vision(HIW "$N突然觉得真气冲顶。原来是$N的无极心法进入了第"+chinese_number(stage(level))+"重境界！\n" NOR, me);

		}
	}
			
}
