// baiyun-sword.c 白云剑法
//created 17-06-2001 海上飘(piao)

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$N使一招"+BLINK""+HIB"「峰回路转」"NOR""NOR"，手中$w如一条银蛇般刺向$n的$l",
		"dodge":		0,
		"damage":		100,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N使出白云剑法中的"+BLINK""+HIM"「空山鸟语」"NOR"，剑光霍霍斩向$n的$l",
		"dodge":		0,
		"damage":		90,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N一招"+BLINK""+HIW"「御风而行」"NOR"，身形陡然滑出数尺，手中$w斩向$n的$l",
		"dodge":		0,
		"damage":		140,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手中$w中宫直进，一式"+BLINK""+HIR"「旭日东升」"NOR"对准$n的$l刺出一剑",
              "damage":		60,
		"dodge":		0,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N纵身一跃，手中$w一招"+BLINK""+HIY"「金光泻地」"NOR"对准$n的$l斜斜刺出一剑",
              "damage":		60,
   		"dodge":		0,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的$w凭空一指，一招"+BLINK""+HIC"「童子引路」"NOR"刺向$n的$l",
		"dodge":		0,
		"damage":		80,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N手中$w向外一分，使一招"+BLINK""+HIG"「柳暗花明」"NOR"反手对准$n$l一剑刺去",
		"dodge":		0,
		"damage":		60,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N横剑上前，身形一转手中$w使一招"+BLINK""+HIW"「空谷秋虹」"NOR"画出一道光弧斩向$n的$l",
		"dodge":		0,
		"damage":		100,
		"damage_type":	"割伤"
	]),
            ([      "action":           "$N横剑上前，身形一转手中$w使一招"+BLINK""+HIW"「仙云密布」"NOR"画出一道光弧刺向$n的$l",
                "dodge":           -10,
                "damage":          150,
                "damage_type":  "刺伤"
        ]),



});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练白云剑法。\n");

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
		return notify_fail("你的内力或气不够，没有办法练习白云剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按着所学练了一遍白云剑法。\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("youxia") + "/baiyun-sword/" + action;
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$n使出一招「凤舞九天」，手中的$v化作一条长虹，磕开了$N的$w。\n",
        "$n使出「封」字诀，将$N的$w封于丈外。\n",
        "$n使出一招「朝朝瑞雪」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「旱地春雷」，向$N拿$w的手腕削去。\n",
});

string *unarmed_parry_msg = ({
        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
        "$n反手一招「阳光普照」，整个人消失在一团剑光之中。\n",
        "$n使出一招「龙舞九天」，$v直刺$N的双手。\n",
        "$n将手中的$v化做七条剑气，迫得$N连连后退。\n",
});
