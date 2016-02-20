#include <weapon.h>
inherit STAFF;

void create()
{
        set_name("长杖", ({ "long zhang", "zhang", "staff" }));
        set_weight(5000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "这是一柄普通的长杖。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「唰」的一声抽出一柄$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
}
        init_staff(10);
        setup();
}
