//by tianlin@mhxy for 2001.9.10

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }
int valid_learn(object me) { return 1;}


int practice_skill(object me)
{
	return notify_fail("武当心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
	return CLASS_D("wudang") + "/wudang-force/" + func;
}
