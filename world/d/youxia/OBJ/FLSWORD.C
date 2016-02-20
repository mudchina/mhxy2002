// flsword.c   楚留香的風流劍    created 17-06-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC"風流劍"NOR, ({ "fengliu sword", "fengliu", "sword" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把剑身上有一道暗红色血槽的长剑。\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", "$N从银色剑鞘中抽出一把有一道暗红色血槽的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的银色剑鞘。\n");
        }
        init_sword(160);
        setup();
}
 
