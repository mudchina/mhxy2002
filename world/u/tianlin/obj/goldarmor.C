//By tianlin@mhxy for 2002.1.4

#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(HIY "黄金战甲" NOR, ({"gold armor","zhanjia", "jia", "armor"}));
        set("value", 500000);
             set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	         set("long", "一件由黄金制成的宝甲．\n");
                set("material", "steel");
                set("armor_prop/armor", 150);
	         set("armor_prop/dodge", -5);
        }
        setup();
}



