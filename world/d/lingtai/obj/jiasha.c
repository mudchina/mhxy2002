// By tianlin 2001.5.8
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name(WHT"水晶"CYN"战袍"NOR, ({"shuijing pao", "pao", "cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long"," 一件水晶做的战袍,据说是孙悟空用的。\n");
                set("material", "cloth");
                set("unit", "件");
                set("value", 10000);
                set("armor_prop/spells", 20);
                set("armor_prop/dodge", 20);
                set("armor_prop/armor", 100);
     set("armor_prop/personality", 2);
        }
        setup();
}
