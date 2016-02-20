//by tianlin 2001.8.6.制作
#include "/doc/help.h"
#include "ansi.h"
inherit F_CLEAN_UP;
int main(object ob,string arg)
{
    int force, mana;
    object me=this_player();
if((me->query("age")<=16)&&(me->query("combat_exp")<=400000))
{
    force = (int)me->query("max_force");
    mana  = (int)me->query("max_mana");
    me->set("force",force*2);
    me->set("mana",mana*2);
    me->set("food",me->max_water_capacity()*3);
    me->set("water",me->max_food_capacity()*3);
    write("恢复成功！\n");
    return 1;
}
else
{     return notify_fail(HIW"你这也叫新手，想用BUG吗? \n"NOR+HIR"真不要脸.\n"NOR);
}
}
int help()
{
       write( @TEXT
指令格式：mhxy
这个指令让你加满内力和法力
只适合新手。
TEXT
       );
       return 1 ;
}
