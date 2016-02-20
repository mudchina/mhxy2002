// jinsijia.c 金丝
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("金丝甲", ({"jinsi armor","jinsi", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件金丝织就的宝甲．\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 200);
		set("armor_prop/dodge", 15);
        }
        setup();
}


