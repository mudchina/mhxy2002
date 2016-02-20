// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N手中的$w迎风一晃，刀锋带出裂锦般的声音，万马奔腾般地砍向$n的$l",
                "dodge":                -20,
                "damage":               25,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中的$w迎风狂舞，象暴风中的滚沙，裹向$n的$l",
                "dodge":               -20,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中的$w象狂风中的流云，忽聚忽散地砍向$n的$l",
                "dodge":                -15,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N晃动手中的$w，刀光忽隐忽现，象秋风中的落叶，一刀连一刀地散向$n的$l",
                "dodge":                -20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N聚起全身的功力，手中的$w象刺骨寒风般割向$n",
                "dodge":                -15,
                "damage":               25,
                "damage_type":  "割伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query_skill("zanglong-force", 1) < 10 )
                return
                notify_fail("你的内功心法火候不足，无法练斩马刀。\n");
        return 1;
}

int valid_enable(string usage)
{
        return (usage=="blade") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int learn_bonus()
{
        return 0;
}
int practice_bonus()
{
        return -5;
}
int black_white_ness()
{
        return 0;
}
int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
        return CLASS_D("yujian") + "/zhanma-blade/" + action;
}