#include <weapon.h>
#include <ansi.h>

inherit SPEAR;
inherit F_UNIQUE;

void create()
{
        set_name("火云枪",({ "huoyun qiang", "huoyun", "spear", "qiang" }) );
        set_weight(20000);
if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 0);
                set("rigidity", 9);
                set("sharpness", 9); 
                set("no_get", 1);
                set("material", "steel");
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5); 
                set("wield_neili", 300);
                set("wield_maxneili", 700);
                set("wield_str", 22);
                set("wield_msg", HIY"$N“唰”的一声抽出一把火云枪。\n"NOR);
                set("long", "这是一柄火云枪。\n");                
                set("unwield_msg", HIY "火云枪幻作一道白光，「唰」地飞入腰间。\n" NOR);                
}
        init_spear(80);
        setup();
}
