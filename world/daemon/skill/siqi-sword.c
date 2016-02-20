#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	
		"action":		"$N使一招「苍松迎客」，身形暴长，手中$w一摆，向$n的$l刺去",
		"dodge":		50,
		"force":		170,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N身形拔地而起，手中$w舞动，满天剑气森森，一招「浮云漂渺」罩向$n的$l",
		"dodge":		-70,
		"force":		200,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N手中$w光芒闪闪，一招「飞瀑流泉」，瞬间已向$n的$l连攻数剑",
		"dodge":		-40,
		"damage":		90,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N手中$w一圈，带起满天沙尘，突然剑身一颤，化出无数剑尖，一招「怪石峥嵘」笼住$n的$l",
		"dodge":		-40,
		"damage":		40,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N$w闪动，幻出满天剑影，团团簇簇，一招「梦笔生花」往$n$l刺去",
		"dodge":		60,
		"damage":		120,
		"damage_type":	"刺伤"
	]),
	([	
		"action":		"$N身行跃起，手中$w挽出朵朵剑花，一招「喜鹊登梅」裹住$n的全身",
		"dodge":		-60,
		"damage":		150,
		"damage_type":	"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;
//       if( (string)me->query("gender") != "女性" )
//                return notify_fail("四奇剑法是只有女子才能练的武功。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练四奇剑法。\n");
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
		return notify_fail("你的内力或气不够，没有办法练习四奇剑法。\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	write("你按著所学练了一遍四奇剑法。\n");
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
        return CLASS_D("zhenyuan") + "/siqi-sword/" + action;
}

int effective_level() { return 10;}

string *parry_msg = ({
        "$n使出「桃源探幽」，手中$v曲曲折折，将$N手中的$w引偏了出去。\n",
	"$n$v飘忽不定，一招「飞凤青鸾」竟从意想不到的角度架住了$N手中的$w。\n",
	"$n手中的$v布满内力，一招「古柏劲松」，急削$N握$w的手指。\n",
	"$n手中的$v急运如飞，剑气连绵有如群山，一招「群峰叠翠」，锁住了$N的$w。\n",
});

string *unarmed_parry_msg = ({
        "$n手中$v圆转，内力激荡，一招「云山雾绕」，强劲的剑气逼得$N连联后退。\n",
	"$n手中$v鼓出凛凛剑气，一招「引人入胜」，带得$N站立不稳。\n",
	"$n$v虚晃，身随剑势，在空中盘旋，一招「飞去来兮」，消失得无影无踪。\n",
	"$n转身，$v一招「云笼奇峰」，泛起一片光芒，将自己全身护得密不透风。\n",
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
	return 0;
}
int black_white_ness()
{
	return 0;
}

