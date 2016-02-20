// 龟仙神甲 by Calvin

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIW"龟仙神铠"NOR, ({"guixian shenkai","shenkai","jia", "guixian", "armor"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件来自龟仙岛的神衣,是用海底贝壳制成的。\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 120);
                set("armor_prop/dodge", -100);
                set("armor_prop/parry", -100);
                set("armor_prop/force", 200);
                set("armor_prop/spells", 200);
        }
        setup();
}
