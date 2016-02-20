//By tianlin@mhxy for 2001.12.15

inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "name":                 "",
                "action":
"$N斜步飞身向上，手中$w迎风一晃，闪电般劈向$n的后脑",
                "dodge":                0,
		"parry":		-20,
                "damage":               35,
                "damage_type":  "劈伤"
        ]),
        ([      "name":                 "",
                "action":
"$N缩身一个滚翻，$w随身而走，悄无声息地劈向$n的双脚",
                "dodge":                -10,
		"parry":		0,
                "damage":               35,
                "damage_type":  "割伤"
        ]),
        ([      "name":                 "",
                "action":
"$N双手一振，$w突发血光，「\t"HIY"人\t"HIB+BLINK"魔\t"NOR+HIR"神"NOR"\t」一连三刀向$n刺去",
                "dodge":                5,
		"parry":		-15,
                "damage":               45,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "",
                "action":
"$N脸上突然紫气大做，手中$w挟着一股血腥劈向$n的$l",
                "dodge":                5,
		"parry":	-5,
                "damage":               40,
                "damage_type":  "劈伤"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if(  !(ob = me->query_temp("weapon"))
        ||     (string)ob->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀才能学神极刀法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="parry"||usage=="blade";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{

        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 10 )
                return notify_fail("你的内力或气不够，没有办法练习神极刀法。\n");

        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍神极刀法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("shenjian") + "/shenji-blade/" + func;
}


