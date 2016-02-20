#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(BLU"野味"NOR, ({"liewu", "lie"}));
    set_weight(5000);
    set("long", "一盘上好的野味\n");
    set("unit", "盘");
        set( "value", 2000 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
