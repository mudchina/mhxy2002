#include <weapon.h>
inherit SPEAR;

void create()
{
        set_name("长枪", ({ "long spear", "spear", "qiang" }));
        set_weight(5000);
     if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄普通的精钢枪。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");
}
        init_spear(10);
        setup();
}
