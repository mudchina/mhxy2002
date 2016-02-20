// 风天神紫云步
//creay by focus

inherit SKILL;

string *dodge_msg = ({
        "$n提气轻身，已转到$N的身后\n",
        "$n旋空而起，$N眼前已然失去$n的身影。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 0 )
                return notify_fail("你的内力不够，没有办法练风天神紫云步。\n");

        return 1;
}
string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("你的气或内力不够，不能练风天神紫云步。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

string perform_action_file(string func)
{
        return CLASS_D("lingjie")+"/fengtian-steps/" + func;
}
