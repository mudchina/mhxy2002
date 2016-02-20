//By tianlin@mhxy for 2001.12.5

// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// cloudforce.c
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("飞云心法只能用学的，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("shenjian") + "/cloudforce/" + func;
}

