//【灵犀一指】lingxiyizhi.c
// created 17-06-2001 海上飘(piao)
#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":
"$N大吼一声，十指上下分飞，一招"+BLINK""+HIG"「翩若蘭召翡」"NOR"，双指直取$n的$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		150,
		"damage_type":		"刺伤",
		"weapon" :		"右手五指",
	]),
           ([	            "action":
"$N十指互错，虚幻虚实，一招"+BLINK""+HIM"「惟愁捉不住」"NOR"，前后左右，瞬息间向$n攻出了六招",
		"dodge":		-20,
		"parry":		-20,
		"force":		150,
		"damage_type":		"刺伤",
		"weapon" :		"右手五指",
	]),
	([	"action":
"$N左掌竖立胸前，一式"+BLINK""+HIR"「婉若丹鳳舉」"NOR"，右手食指扣住拇指，轻轻对着$n一弹",
		"dodge":		10,
		"parry":		-20,
		"force":		100,
		"damage_type":		"刺伤",
		"weapon":		"右手五指",
	]),
	([	"action":
"$N双掌化指，指中带掌，双手齐推，一招"+BLINK""+HIW"「飛去逐驚鴻」"NOR"，一股排山倒海的内力，直扑$n$l",
		"dodge":		-10,
		"parry":		-20,
		"force":		120,
		"damage_type":		"刺伤",
		"weapon":		"右手五指",
	]),
	([	"action":
"$N一招"+BLINK""+HIC"「翩若蘭召翡」"NOR"，右手一拳击出，左掌化指，一掌一指凌空击向$n的$l",
		"dodge":		10,
		"parry":		-10,
		"force":		100,
		"damage_type":		"刺伤",
		"weapon":		"右手五指",
	]),
            ([	"action":
"$N突然身行急转，一招"+BLINK""+HIY"「惟愁捉不住」"NOR"，十指飞舞，霎时之间将$n四面八方都裹住了",
		"dodge":		0,
		"parry":		-20,
		"force":		150,
		"damage_type":		"内伤",
		"weapon":		"右手五指",
	]),
            ([	"action":
"$N一式"+BLINK""+HIC"「婉若丹鳳舉」"NOR"，并指如刃，一束束锐利无俦的刀气，凌虚向$n的$l砍去",
		"dodge":		10,
		"parry":		-30,
		"force":		180,
		"damage_type":		"刺伤",
		"weapon":		"右手五指",
	]),
      ([	"action":
"忽听嗤嗤轻响，一股柔和的气流自$N手指涌出，正是一招"+BLINK""+HIB"「飛去逐驚鴻」"NOR"，缓缓点向$n$l",
		"dodge":		10,
		"parry":		-30,
		"force":		180,
		"damage_type":		"刺伤",
		"weapon":		"右手五指",
	]),

});

int valid_learn(object me)
{
		if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("灵犀一指必须空手练习。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query_skill("unarmed",1) < (int)me->query_skill("lingxiyizhi",1)/2)
                return notify_fail("你的扑击格斗还不够精湛，无法领会更深层的灵犀一指！\n");

	if( (int)me->query("sen") < 50)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");

	if( (int)me->query("kee") < 50 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -20);

	return 1;
}

string perform_action_file(string func)
{
	return CLASS_D("youxia") + "/lingxiyizhi/" + func;
}
