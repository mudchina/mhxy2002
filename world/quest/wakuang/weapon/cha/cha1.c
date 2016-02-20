#include <weapon.h>
inherit FORK;

void create()
{
        set_name("铜叉", ({ "tong fork", "fork", "cha" }));
        set_weight(5000);
        if (clonep())
set_default_object(__FILE__);
else {
                set("unit", "柄");
                set("long", "这是一根普通的铜叉。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n插回背后。\n");
}
        init_fork(10);
        setup();
}
