// yulong-steps.c 身法

inherit SKILL;

string *dodge_msg = ({
        "但是$n身形一转，使出「龙游九天」，蓦地不见，避开了这一招。\n",
        "$n一招「御龙摆尾」，身随意转，倏地往一旁挪开了三尺。\n",
        "$n身形飘忽，瞻之在前，忽焉在后，却是「龙飞凤舞」的身法。\n",
        "$n使出「龙腾虎跃」，犹如在水面滑行一般，身形晃了开去。\n",
        "可是$n的身影飘飘渺渺，竟丝毫不着力，正是一式「虎距龙盘」。\n"
});

int valid_enable(string usage)
{
        return (usage == "dodge") || (usage == "move");
}

int valid_learn(object me) { return 1; }

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 35 )
                return notify_fail("你的体力太差了，不能练御龙身法。\n");
        me->receive_damage("kee", 25);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("bibotan") + "/yulong-steps/" + action;
}

