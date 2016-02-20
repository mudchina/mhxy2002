// 血浪 xue lang.c     created 17-06-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(RED"血浪"NOR, ({"xue lang","sword" }));
	set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把几乎拿在手中没有重量的宝剑，是剑中极品。\n");
                set("unit", "把");
                set("value", 40000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(160);
        setup();
}

