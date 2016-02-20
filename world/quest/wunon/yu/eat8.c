// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIM"螃蟹"NOR, ({"yu8"}));
    set_weight(30000);
    set("long", "一个大大的螃蟹\n");
    set("unit", "个");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

        set( "value", 800 + random( 800 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}

