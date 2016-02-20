// by mhsj@gslxz 2001/3/12
// jinjia.c 金甲
#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(HIY "金环锁子甲" NOR, ({"golden armor","jinjia", "jia", "armor"}));
        set("value", 500000);
             set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件金丝织就的宝甲．\n");
                set("material", "steel");
                set("armor_prop/armor", 80);
		set("armor_prop/dodge", -5);
        }
        setup();
}



