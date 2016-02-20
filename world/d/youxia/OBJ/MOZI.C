// 墨子剑 mozi sword.c        created 17-06-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(BLK"墨子剑"NOR, ({"mozi sword","sword","mozi"}));
	set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把黑色的木剑，但其重量不下百斤，是剑中极品。\n");
                set("unit", "把");
                set("value", 40000);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
        }
        init_sword(130);
        setup();
}

