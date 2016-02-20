//by ephq

#include <ansi.h>

inherit SKILL;
int valid_learn(object me)
{
          if ( me->query("xiuluo/jinchanzi") != "done")
        return notify_fail("要想学会乾坤点穴大法只能读乾坤图。\n");
        return 1;
}

string perform_action_file(string func)
{
	return __DIR__"dianxue/" + func;
}

string type() { return "knowledge"; }