// zouxiao.c by yushu 2000.11
//xixi
//等级的描述我是照着字典写的,可能跟xyj2000不一样,因为我从没学过zouxiao
#include <ansi.h>
inherit SKILL;
int valid_learn(object me) { return 1; }
string level_description(int level)
{
	int grade;
	string *level_desc = ({
		BLU "五音不全" NOR,
		HIB "杂乱无章" NOR,
		HIY "初懂乐理" NOR,
		HIC "精通音律" NOR,
		YEL "有声有色" NOR,
		HIM "引吭高歌" NOR,
		WHT "栩栩如生" NOR,
		CYN "画龙点睛" NOR,
		HIG "巧夺天工" NOR,
		HIW "箫技无双" NOR,
	});

	grade = level / 20;

	if( grade >= sizeof(level_desc) )
		grade = sizeof(level_desc)-1;
	return level_desc[grade];
}
