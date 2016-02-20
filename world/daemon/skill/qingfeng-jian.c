//By tianlin@mhxy for 2002.1.25,从新编写shenjian 技能状态

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"name":			"春风乍起",
		"action":		"$N使一招"HIR"「"BLINK+HIY"春风乍起"NOR+HIR"」"NOR"，手中$w如和煦春风洒向$n的$l，没有人知道风从哪里来，也就无法抵挡",
              "parry":   -40,
              "dodge":   -40,
		"damage":		70,
		"damage_type":	"刺伤"
	]),
	([	"name":			"细雨绵绵",
		"action":		"$N手中的$w一招"HIR"「"BLINK+HIB"细雨绵绵"NOR+HIR"」"NOR"如绵绵细雨，无孔不入的刺向$n的$l",
              "parry":   -50,
              "dodge":   -50,
              "damage":               50,
		"damage_type":	"刺伤"
	]),
	([	"name":			"飞星传恨",
		"action":		"$N舞动$w，一招"HIR"「"BLINK+HIG"飞星传恨"NOR+HIR"」"NOR"，剑如飞星人如闪电，人剑合一，扑向$n的$l",
              "parry":   -60,
              "dodge":   -60,
              "damage":               100,
		"damage_type":	"刺伤"
	]),
	([	"name":			"柔情似水",
		"action":		"$N一抖手中$w，使出"HIR"「"BLINK+HIW"柔情似水"NOR+HIR"」"NOR"，不由得暗自情伤，以情驭剑，向$n的$l刺出一剑",
              "parry":   -70,
              "dodge":   -70,
              "damage":               60,
		"damage_type":	"刺伤"
	]),
	([	"name":			"织云弄巧",
		"action":		"$N手中$w剑光四散，一招"HIR"「"BLINK+HIC"织云弄巧"NOR+HIR"」"NOR"，剑光如云，笼罩了$n的$l，令人不知剑来自何方",
              "parry":   -80,
              "dodge":   -80,
              "damage":               90,
		"damage_type":	"刺伤"
	]),
	([	"name":			"佳期如梦",
		"action":		"$N想起年少玩伴尢在倚门相望，手中$w直指$n$l，一招"HIR"「"NOR+BLINK+MAG"佳期如梦"NOR+HIR"」"NOR"，刺出了惊天动地的一剑",
              "parry":   -90,
              "dodge":   -90,
		"damage":		50,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("你的内力不够，没有办法练清风细雨温柔剑法。\n");

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
	||	(int)me->query("force") < 5 )
		return notify_fail("你的内力或气不够，没有办法练习清风细雨剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍清风细雨剑法。\n");
	return 1;
}
int effective_level() { return 20;}
string *parry_msg = ({
        "$n左掌攻敌，右剑防身，一招「情海无涯」，手中的$v狠狠磕开了$N的$w。\n",
	"$n剑出连环，绕住$N的$w，一招「朝朝暮暮」竟使$N难以把持手中的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n使出一招「金风玉露」，亦守亦攻，竟使$N不知是攻是守。\n",
	"$n一抖手中的$v，使出一招「两情相悦」，手中的$v配合左掌，将全身团团罩住。\n",
	
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return -100;
}
int black_white_ness()
{
	return -10;
}

string perform_action_file(string action)
{
        return CLASS_D("shenjian") + "/qingfeng-jian/" + action;
}


