#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIR"血果"NOR, ({ "xue guo","guo"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "on");
                set("unit", "个");
                set("long", "一个血红色肯定不大好吃的果子。\n");
                set("value", 1);
		set("water_remaining", 1);
		set("water_supply", 100);
        }
}  
