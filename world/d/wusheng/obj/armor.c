// wusheng-armor.c 武圣战甲

#include <ansi.h>
#include <armor.h>

inherit F_UNIQUE;
inherit ARMOR;

void create()
{
        set_name(HIC"武圣战甲"NOR, ({"wusheng armor","zhanjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件用万年天蚕丝穿连灵山翠玉制作而成的护甲。\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);		
                set("material", "crimsonsteel");
                set("value", 10000);
                set("armor_prop/armor", 70);
		set("armor_prop/dodge", -5);
        }
        setup();
}


