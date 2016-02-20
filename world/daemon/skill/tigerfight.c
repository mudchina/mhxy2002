inherit SKILL;
mapping *action = ({
        ([      "action":               
"$N使出一招「天虎扑式」，右掌穿出击向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「天虎剪式」，左掌化虚为实击向$n的$l",
                "dodge":                -10,
                "parry":                -30,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出虎掌中「天虎扫式」，如猛虎般欺至$n身前，一掌拍向$n的$l",
                "dodge":                -30,
                "parry":                10,
                "force":                70,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「天虎擒式」，对准$n的$l连续拍出三掌",
                "dodge":                10,
                "parry":                -30,
                "force":                130,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「天虎啜式」击向$n$l",
                "dodge":                10,
                "parry":                5,
                "force":                120,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N使出「天虎七式」，身形散作七处同时向$n的$l出掌攻击",
                "dodge":                10,
                "parry":                10,
                "force":                120,
                "damage_type":  "内伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「九重天虎」双掌并力推出",
                "parry":                10,
                "dodge":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
});

int valid_learn(object me)
{
        object ob;
   if (me->query("betray/count"))
     return notify_fail("你判离师门，无缘学得天虎掌。\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
   return notify_fail("天虎神掌需配合血魔神功才可发挥威力。\n");
        if( (int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够，无法学习天虎神掌。\n");

        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练虎掌必须空手。\n");
        return 1;
}
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50 )
                return notify_fail("你的体力不够了，休息一下再练吧。\n");
        if( (int)me->query("force") < 10 )
                return notify_fail("你的内力不够了，休息一下再练吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);

   if (me->query("betray/count"))
     return notify_fail("你求学之心不专，无缘学天虎神掌。\n");
   if( (string)me->query_skill_mapped("force")!= "evil-force")
     return notify_fail("天虎神掌需配合魔功才能练。\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("evil") + "/tigerfight/" + action;
}
