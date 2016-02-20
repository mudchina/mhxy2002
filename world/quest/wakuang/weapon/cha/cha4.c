#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name("¾Å¹É¸Ö²æ",({ "steel fork", "cha", "fork" }) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 0);
                set("treasure",1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("unique", 1);
                set("weapon_prop/dodge", -2);
                set("weapon_prop/parry", 1);        
                set("material", "steel");
}
        init_fork(60);
        setup();
}
