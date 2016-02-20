#include <armor.h>
inherit BOOTS;

void create()
{
                set_name("¸ß¸úÐ¬", ({"gao gen xie", "shoes","xie" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 20);
                set("armor_prop/dodge", 20);
        }
        setup();
}
