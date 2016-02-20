#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"锦绣白袍"NOR, ({"white cloth", "cloth"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("long", "一件雪白的布袍，一丝杂色也没有．\n");
                set("unit", "件");
                set("value", 20000);
                set("armor_prop/armor", 35);
                set("armor_prop/intelligence", 4);

        }
        setup();
}

