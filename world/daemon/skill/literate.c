// literate.c

#include <ansi.h>

inherit SKILL;

string type() { return "knowledge"; }

string level_description(int level)
{
	int grade;
	string *level_desc = ({
	BRED+	BLU "初通文理" NOR,
	BRED+	BLU "略知一二" NOR,
	BYEL+	HIB "知书达理" NOR,
	BYEL+	HIB "文采斐然" NOR,
	BBLU+	YEL "博学多才" NOR,
	BBLU+	YEL "高才硕望" NOR,
	BRED+	HIG "饱学鸿儒" NOR,
	BMAG+	HIW "学贯古今" NOR
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}

