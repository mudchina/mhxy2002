// cloudy_shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
        set_name(HIW "·ïÁèÌ¤ÔÆÑ¥" NOR, ({"cloudy shoes","shoes"}));
        set_weight(1000);
        set("long", "Ò»Ë«·ïÎÆÐå±ßµÄÌ¤ÔÆÑ¥£®\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather");
                set("unit", "Ë«");
                set("value",100000);
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 20);  
        }
        setup();
}

