inherit SKILL;

#include <ansi.h>

string level_description(int level)
{
        if ( level < 10 )
                return BLU "发呆初始" NOR;
        else if ( level < 30 )
                return HIB "渐入呆途" NOR;
        else if ( level < 60 )
                return YEL "日见呆滞" NOR;
        else if ( level < 100 )
                return CYN "呆头呆脑" NOR;
        else if ( level < 150 )
                return HIW "呆若木鸡" NOR;
        else
                return HIR "无可救药" NOR;
}
int valid_enable(string usage)
{
        return usage=="force";
}
int practice_skill(object me)
{
        return notify_fail("发呆神功只能向师父学，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("idle-force") + "/idle-force/" + func;
}

