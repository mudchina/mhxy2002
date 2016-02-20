// rake.c

#include <ansi.h>;
#include <weapon.h>

inherit RAKE;

void create()
{
        set_name(HIW"九齿冰耙"NOR, ({ "bing pa", "pa","rake" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 1000);
                set("material", "iron");
                set("long", HIW"一柄长长的九齿冰耙。\n"NOR);
                set("wield_msg", "$N抄起一柄$n，在头上挥舞了一圈。\n");
        }
        init_rake(90);
        setup();
}

