// force.c

#include <ansi.h>

inherit SKILL;
int valid_learn(object me) { return 1; }
string level_description(int level)
{
	int grade;
	string *level_desc = ({
BLU "典型色盲" NOR,
HIB "能辨红绿" NOR,
HIY "可识香臭" NOR,
HIC "略通园艺" NOR,
YEL "识花有术" NOR,
HIM "闻香辩类" NOR,
WHT "妙手生春" NOR,
CYN "采花有术" NOR,
HIG "巧夺天工" NOR,
HIW "园艺无双" NOR,
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
