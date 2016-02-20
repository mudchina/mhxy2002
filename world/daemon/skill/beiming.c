// celestial.c

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
        if( (int)me->query("bellicosity") < (int)me->query_skill("beiming",1) * 10 )
                return notify_fail("你的杀气不够，无法领悟更高深的北冥神功。\n");

/*	if( (int)me->query_skill("beiming", 1) >= 250 )
		return notify_fail("你的气量有限，对北冥神功已领悟到了极限。\n");
*/
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("北冥神功只能用学习或应用中提高！\n");
}

string exert_function_file(string func)
{
        return CLASS_D("kof") + "/beiming/" + func;
}

