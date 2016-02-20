#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(BLU"鱼肉"NOR, ({"yu luo", "yu"}));
    set_weight(5000);
    set("long", "一盘上好的鱼肉\n");
    set("unit", "盘");
        set( "value", 2000 );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
