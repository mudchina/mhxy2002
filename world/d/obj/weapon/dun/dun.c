#include <armor.h>

inherit SHIELD;

void create()
{
        set_name( "青萝藤盾" , ({"qingluo dun","shield", "dun", "qingluo"}) );
		set("long", "世界上最好的盾之一。\n");
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("material", "wood");
                set("value", 1000);
                set("armor_prop/armor", 100);
        }
        setup();
}


   