// by mhsj@gslxz 2001/3/12

// kaijia.c 铠甲
#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(CYN "重钢铠甲" NOR, ({"zhonggang armor","kaijia", "jia", "armor"}));
        set("value", 700000);
             set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件防御力极强而又非常重的宝甲．\n");
                set("material", "steel");
                set("armor_prop/armor", 80);
		set("armor_prop/dodge", -50);
        }
        setup();
}



