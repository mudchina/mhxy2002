#include <weapon.h>

inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name("铁叉", ({ "tie fork", "cha", "fork" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","一根铁叉。\n");
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
        init_fork(30);
        setup();
}
