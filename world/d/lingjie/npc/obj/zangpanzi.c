//link

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("脏盘子",({ "panzi","zang panzi" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"一个脏兮兮的盘子。\n");
		set("unit", "堆");
		set("base_unit", "个");
		set("base_weight", 1);
		set("base_value", 1);
	}
	set_amount(1);
	init_throwing(4);
	setup();
}
