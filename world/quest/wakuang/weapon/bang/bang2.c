#include <weapon.h>

inherit STICK;
inherit F_UNIQUE;
void create()
{
        set_name("大棒", ({ "da bang", "bang", "stick" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
        set("unit", "把");
        set("long","一根大棒。\n");
        set("value", 0);
        set("unique", 1);
        set("rigidity", 1);
        set("sharpness", 1);
        set("material", "blacksteel");
        set("weapon_prop/dodge", 2);
        set("treasure",1);
        set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
        set("unequip_msg", "$N将手中的$n插入腰间。\n");
}
        init_stick(30);

        setup();
}