// 段剑 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIB"断剑"NOR, ({ "duan sword", "jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 10000);
               set("no_sell", "卖?别逗了,这种罕见的东西可以买卖吗!\n");
                set("material", "steel");
                set("long", "这是一把只有一半剑身的断剑。\n");
                set("wield_msg", "一道青光闪过，$N手中已多了把$n。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(120);
        setup();
}
