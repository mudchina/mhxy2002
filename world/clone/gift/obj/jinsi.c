// jinjia.c 金甲
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("金丝宝甲", ({"jinsi baojia","baojia", "jia", "armor"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "江湖至宝金丝宝甲是每个习武之人心仪的防具．\n");
                set("material", "steel");
                set("value", 0); 

                set("no_give",1);
                set("armor_prop/armor", 60);
        }
        setup();
}


