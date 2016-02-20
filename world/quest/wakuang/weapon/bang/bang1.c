#include <weapon.h>
inherit STICK;

void create()
{
        set_name("木棒", ({ "mubang", "bang", "stick" }));
        set_weight(5000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "柄");
        set("long", "这是一根普通的木棒。\n");
        set("value", 0);
        set("material", "steel");
        set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n插回剑鞘。\n");
}
        init_stick(10);
        setup();
}
