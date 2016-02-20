// lightarmor.c
#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIW "晶碳护甲" NOR, ({"hu jia","jia","armor"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
        set("long", "高科技产品。\n");
                set("value", 1);
                set("material", "???");
                set("armor_prop/armor", 50);
                set("armor_prop/armor_vs_force", 50);
             }
                         setup();
}

