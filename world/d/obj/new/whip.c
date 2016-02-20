// whip.c 
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit WHIP;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"烈火" NOR+HIC "鞭" NOR, ({"liehuo bian", "bian", "whip"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "支");
                set("long", "鞭身上缠绕着地心深处的火焰。\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIR "只听「轰」的一声，地狱中的烈火化为一把神鞭落在$N手里。\n" NOR);
                set("unwield_msg",HIR "$N将手中的$n"+HIR "向地上一插，神鞭顿时化为一股烈火消失了。\n"NOR);
                             set("weapon_prop/cor", 1);
}
        init_whip(120);
        setup();
}
