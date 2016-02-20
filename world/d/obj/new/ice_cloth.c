// pao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(MAG "冰丝岩溶衣" NOR, ({"ice cloth","cloth"}));
        set_weight(1000);
        set("long", "这是用岩浆中的冰丝所编织的战袍，珍贵之极。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
                set("value", 100000);
                set("armor_prop/armor", 100);
        }
        setup();
}

