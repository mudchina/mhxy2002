#include <weapon.h>
#include <ansi.h>
inherit BLADE;
inherit F_UNIQUE;
void create()
{
        set_name(RED"烈焰刀"NOR, ({ "lieyan dao", "dao", "lieyan", "blade" }) );        
        set_weight(7000);
    if (clonep())
                set_default_object(__FILE__);
        else {
           set("value", 0);
           set("rigidity", 2);
           set("sharpness", 2);
           set("unique", 1);
           set("treasure",1);
           set("wield_force", 100);
           set("wield_maxforce", 1000);
           set("wield_str", 22);
           set("unit", "把");
           set("long", RED"此刀刀面如有火光流动，刀鞘上镶著“烈焰”两个古篆，乃是明教的镇教宝物，平时都供奉在光明宝塔之内。\n"NOR);
}
        init_blade(80);
        setup();
}
