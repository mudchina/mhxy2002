// 毛笋 /clone/eat/food/mao_sun.c
// by lala, 1997-12-16

#include <ansi.h>

inherit ITEM;

inherit F_FOOD;

void create()
{
    set_name( GRN"毛笋"NOR, ({"mao sun","sun"}) );
    set_weight( 30000 );
    if ( clonep() )
            set_default_object( __FILE__ );
    else {
        set( "long", @LONG
碧绿的毛笋，体大肉肥，鲜美可口，是宜兴的特产。
LONG
        );
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);

        set( "unit", "枝" );
        set( "value", 400 + random( 600 ) );
        set( "food_remaining", 5 );
        set( "food_supply", 25 );
    }
}

int do_eat( string arg )
{
    return notify_fail("这还是生的，只有熊猫才肯吃。\n");
}
