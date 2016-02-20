// 心叶甲 by Calvin

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIG"心叶甲"NOR, ({"xinye jia","jia", "xinye", "armor"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "一件心叶树的叶子做的铠甲,是传说中心叶童子的宝物。\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 120);
                set("armor_prop/dodge", 100);
                set("armor_prop/parry", 100);
                set("armor_prop/force", 100);
                set("armor_prop/spells", 100);
        }
        setup();
}
