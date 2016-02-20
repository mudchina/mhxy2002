// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name(HIY"鸭梨"NOR, ({"ya li","yali","pear"}));
    set_weight(30000);
    set("long", "一个大大的脆生生黄澄澄的鸭梨");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

        set( "unit", "个" );
        set( "value", 500 + random( 500 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
}
