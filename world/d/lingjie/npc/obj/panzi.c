// pearl.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("洗好的盘子", ({ "panzi"}) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一个洗好的盘子。\n");
		set("unit", "堆");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(3);
	setup();
}
