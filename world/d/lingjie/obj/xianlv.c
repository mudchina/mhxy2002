// shoe.c
#include <armor.h>
inherit BOOTS;

void create()
{
        set_name("оибд", ({ "xianlv shoes", "shoes" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "к╚");
                set("value", 40000);
//                set("material", "cloth");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 10);
        }
        setup();
}

