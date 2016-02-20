
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"浪子游侠剑"NOR, ({"langzi jian", "youxia jian",  "langzi sword", "youxia sword", "sword", "jian"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "游侠儿手中的兵器。\n");
                set("orilong", "游侠儿手中的兵器。\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N冷笑一声，从背后拔出了$n。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中，嘴角多了一丝笑意。\n");
                set("weapon_prop/int", 1);
                        }
        init_sword(80);
        setup();
}

