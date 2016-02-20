// yuchangjian.c 
//creat by lixin

#include <weapon.h>
#include <ansi.h>
inherit MACE;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"惊雷" NOR+HIC "锏" NOR, ({"jinglei jian", "jian", "mace"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "传说雷公所用的武器。\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIG "只听见天上惊雷一响，$N手中多出了一把$n。\n" NOR);
                set("unwield_msg",HIG "$N手中的$n"+HIG "化为雷公，转眼间消失在天空中。\n"NOR);
               set("value", 300000); 
               set("weapon_prop/cor", 1);
}
        init_mace(120);
        setup();
}
