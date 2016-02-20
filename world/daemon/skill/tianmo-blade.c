// updated by ken 2001.3.9
inherit SKILL;
mapping *action = ({
        ([      "action":               "$N祭起魔刃，使出天魔八式中的起手式「万魔初醒」，手中的$w划出一溜光芒斩向$n的$l",
                "parry":                 5,
                "dodge":                -10,
//              "force":                 500,
                "damage":                50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手一抖，顿时魔光大盛，趁$n眼花缭乱之际，手中的$w幻成一片刀花，散向$n的$l",
                "parry":                 10,
                "dodge":                 10,
//              "force":                 500,
                "damage":                50,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               "$N身影晃动，刀锋忽左忽右，手中的$w，从中路突然砍至$n的$l，好一式「天魔独尊」，",
                "parry":                -20,
                "dodge":                -20,
//              "force":                 500,
                "damage":                15,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               "$N刀锋忽转，手中的$w一式「魔光乍现」，闪电般劈向$n的$l",
                "parry":                -20,
                "dodge":                -20,
//              "force":                 500,
                "damage":                15,
                "damage_type":  "劈伤"
        ]),
        ([      "action":               "$N的双脚点地，刀背贴身，全身转出一团刀光滚向$n，好一式「万刃天魔」",
                "dodge":                -20,
                "parry":                -20,
//              "force":                 500,
                "damage":                20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N刀刃向上，一招「天魔回天」，从一个$n意想不到的角度撩向$n的$l",
                "dodge":                -10,
                "parry":                -10,
//              "force":                 500,
                "damage":                30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N手中的$w左右横划，一招「天魔七现」，来来回回地狂扫向$n的$l",
                "dodge":                -10,
                "parry":                -10,
//              "force":                 700,
                "damage":                30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N魔气大盛，使出天魔连环八式中的收手式「万魔归宗」，手中的$w迅捷无比地砍向$n的$l",
                "dodge":                -10,
                "parry":                -10,
//              "force":                 1000,
                "damage":                40,
                "damage_type":  "砍伤"
        ]),
});

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不足，无法练天魔连环八式。\n");
        if( (int)me->query_skill("force", 1) < 20 )
                return notify_fail("你的内功心法火候不足，无法练天魔连环八式。\n");
        if( (int)me->query_skill("evil-force", 1) < 20 )
                return notify_fail("你的魔功火候不足，无法练天魔连环八式。\n");
        if(me->query("family/family_name") != "魔教")
                return notify_fail("天魔八式乃魔教不传之密！\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
                return notify_fail("天魔连环八式需配合魔功才可发挥威力。\n");

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

int practice_skill(object me)
{
        object weapon;

//      if(me->query("family/master_id") != "master feng")
//           return notify_fail("你还不知道怎么练习魔刀。\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
              return notify_fail("你需配合魔功才可能练习刀法。\n");

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
                return notify_fail("你必须先找一把刀，才能练刀法。\n");

        if( (int)me->query("kee") < 40 )
                return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够练这门刀法，还是先休息休息吧。\n");
        me->receive_damage("kee", 40);
        me->add("force", -10);
        write("你按着所学练了一遍天魔八式。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("evil") + "/tianmo-blade/" + action;
}
