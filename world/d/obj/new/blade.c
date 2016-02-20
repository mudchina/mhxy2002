// blade.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
//inherit F_UNIQUE; 
void create()
{
	set_name(BLINK HIW "相思" NOR+HIC "刀" NOR, ({"xiangsi dao", "dao", "blade"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
      set("value", 0);
      set("no_sell",1);
      set("no_give",1);
      set("no_drop",1);
      set("no_get",1);
		set("is_monitored", 1);
		set("material", "steel");
		set("name_recognized", "相思刀");
		set("long", HIW "冷月相思无情刀。\n" NOR);
		set("wield_msg", HIC"$N一声长啸，一道闪电从空中劈过，顿时手中多了一柄$n。\n");
		set("unwield_msg", HIC "$N反手将$n" NOR+HIC"插入鞘中，天空也清朗起来。\n");
	}
	init_blade(120);
	setup();
}
