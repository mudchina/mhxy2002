// gold_armor.c

#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIY "黄金锁子甲" NOR, ({"gold armor","armor"}));
        set_weight(3000);
        set("long", "一副黄金闪闪的宝甲．\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "steel");
                set("unit", "副");
                set("value", 100000);
                set("armor_prop/armor", 195);
                set("armor_prop/dodge", -5);
        }
        setup();
}
