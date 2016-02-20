// created by ken
inherit SKILL;

mapping *action = ({
([      "action": "$N双掌平提聚起一道烈火，劈天盖地的扫向了$n",
        "dodge": -30,
        "parry": 10,
        "force": 200,
        "damage_type": "瘀伤"
]),
([      "action": "$N突然身形飞起，双掌居高临下一招「飞龙在天」拍向$n的$l",
        "dodge": -15,
        "parry": -20,
        "force": 180,
        "damage_type": "瘀伤"
]),
([      "action": "$N右掌一翻，一招「火龙吞日」，迅捷无比地劈向$n的$l",
        "dodge": -10,
        "parry": -10,
        "force": 120,
        "damage_type": "瘀伤"
]),
([      "action": "$N双掌施出一招「怒火腾龙」，隐隐带着风雷之声拍向$n的$l",
        "dodge": -15,
        "parry": -10,
        "force": 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N左掌聚成一团烈火，趁$n一愣猛的推向$n",
        "dodge": -10,
        "parry": 10,
        "force": 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N施出一招「烈火屠龙」，左掌聚起一团火浪猛劈向$n",
        "dodge": -10,
        "parry": 20,
        "force": 150,
        "damage_type": "瘀伤"
]),
([      "action": "$N使出「烈火孽龙」，右掌带着一团腥热的火气从不可能的角度扫向了$n",
        "dodge": 0,
        "parry": 10,
        "force": 100,
        "damage_type": "瘀伤"
]),
([      "action": "$N大吼一声，双掌使出「离火七重」，拍出重重烈火不顾一切般击向$n",
        "dodge": -15,
        "parry": -10,
        "force": 200,
        "damage_type": "瘀伤"
]),
([      "action": "$N临空越起，清啸一声，向$n的连拍数掌",
        "dodge": -10,
        "parry": -10,
        "force": 120,
        "damage_type": "瘀伤"
]),

});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }

int valid_learn(object me)
{
        if(me->query("family/master_id") != "master hate")
            return notify_fail("好像没有人教你怎么练习呀。\n");
        if (me->query("betray/count"))
             return notify_fail("你求学之心不专，无缘学得火龙掌。\n");
        if(me->query("family/family_name") != "魔教")
             return notify_fail("火龙掌乃无恨不传之密！\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
             return notify_fail("火龙掌需配合魔功才可发挥威力。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("练火龙掌必须空手。\n");
        if ((int)me->query_skill("evil-force", 1) < 20)
                return notify_fail("你的魔功火候不够，无法练火龙掌。\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("你的内力太弱，无法练火龙掌。\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if(me->query("family/master_id") != "master hate")
                return notify_fail("你还没得到天尊亲传，不知如何练习这招。\n");
        if (me->query("betray/count"))
                return notify_fail("你判师欺祖，无缘学得火龙掌。\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
                return notify_fail("火龙掌需配合魔功才能练习．\n");       
        if( (int)me->query_skill("evil-force",1) < (int)me->query_skill("huolong-zhang",1)/2)
                return notify_fail("你的魔功还不够精深，练习火龙掌！\n");
        if ((int)me->query("kee") < 40)
                return notify_fail("你的体力太低了。\n");
        if ((int)me->query("force") < 10)
                return notify_fail("你的内力不够练火龙掌。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}
string perform_action_file(string func)
{
return CLASS_D("evil") + "/huolong-zhang/" + func;
}
