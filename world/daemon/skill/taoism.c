// taoism.c  【道学心法】

#include <ansi.h>
inherit SKILL;

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return notify_fail("道学心法只能向师父学或读道德经。\n");
}

string type() { return "knowledge"; }

string level_description(int level)
{
        int grade;
        string *level_desc = ({
                BLU "新入道途" NOR,
                BLU "初领妙道" NOR,
                HIB "略通道行" NOR,
                HIB "元神初具" NOR,
                HIB "道心稳固" NOR,
                CYN "道高德隆" NOR,
                CYN "脱胎换骨" NOR,
                CYN "道满根归" NOR,
                HIC "反璞归真" NOR,
                HIR "天人合一" NOR
        });

        grade = level / 40;

        if( grade >= sizeof(level_desc) )
                grade = sizeof(level_desc)-1;
        return level_desc[grade];
}

int stage(int level)
{
        if( level <10 ) return 1;
        else if ( level < 20 ) return 2;
        else if ( level < 40 ) return 3;
        else if ( level < 70 ) return 4;
        else if ( level < 110 ) return 5;
        else if ( level < 160 ) return 6;
        else if ( level < 220 ) return 7;
        else if ( level < 290 ) return 8;
        else return 9;
}

void skill_improved(object me)
{
        //if stage increased, give bonus...?
        int level = (int)me->query_skill("ningxie-force", 1);
        if ( stage(level) == stage(level-1) + 1)
        {
                //this is to prevent ppls from abondoning skill to get bonus.
                if( (int)me->query("nx-force_bonus") < stage(level) )
                {
                        me->set("nx-force_bonus", stage(level));
//                      me->set("max_force", (int)me->query("max_force") + stage(level)*50 );
                        // mon 12/13/98
                        me->set("maximum_force", 
                                (int)me->query("maximum_force") 
                                + stage(level)*50 );
                        me->save();

                }
        }
                        
}

