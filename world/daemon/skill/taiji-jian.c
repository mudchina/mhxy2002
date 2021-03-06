//[4;53m[1;31mBy tianlin@mhxy for 2001.9.30[2;37;0m

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招"HIR"【"NOR+HIW"太极无门"NOR+HIR"】"NOR"，手中$w如一条银蛇般刺向$n的$l",
		"dodge":		0,
		"damage":		70,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出封山剑法中的"HIR"【"NOR+HIY"御剑降魔"NOR+HIR"】"NOR"，剑光霍霍斩向$n的$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招"HIR"【"NOR+HIC"八方神剑"NOR+HIR"】"NOR"，身形陡然滑出数尺，手中$w斩向$n的$l",
		"dodge":		0,
		"damage":		80,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w中宫直进，一式"HIR"【"NOR+HIG"蜻蜓点水"NOR+HIR"】"NOR"对准$n的$l刺出一剑",
		"dodge":		0,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N纵身一跃，手中$w一招"HIR"【"NOR+HIW"剑身出窍"NOR+HIR"】"NOR"对准$n的$l斜斜刺出一剑",
		"dodge":		0,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w凭空一指，一招"HIR"【"NOR+CYN"来去无踪"NOR+HIR"】"NOR"刺向$n的$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练太极剑法。\n");

	if( (string)me->query_skill_mapped("force")!= "wudang-force")
		return notify_fail("太极剑法必须配合武当派内功才能练。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习太极剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按着所学练了一遍太极剑法。\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("wudang") + "/taiji-jian/" + action;
}
