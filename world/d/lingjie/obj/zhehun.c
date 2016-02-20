// thin_sword.c

#include <weapon.h>

inherit UMBRELLA;

void create()
{
	set_name("遮魂伞", ({ "zhehun san", "umbrella", "san" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 7000);
		set("material", "steel");
		set("long", "这是一把遮魂伞,真正的用途要自己体会了。\n");
		set("wield_msg", "$N「唰」地一声把$n打开握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入身后。\n");
	}
	init_umbrella(30);
	setup();
}
