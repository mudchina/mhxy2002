#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(GRN"蔬菜"NOR, ({"shu cai", "cai"}));
    set_weight(5000);
    set("long", "一盘上好的蔬菜\n");
    set("unit", "盘");
        set( "value", 2000 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
