// changqiang.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit SPEAR;
//inherit F_UNIQUE; 

void create()
{
	set_name(BLINK HIW"惊艳" NOR+HIC "枪" NOR, ({"jingyan spear", "spear"}) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "杆");
      set("value", 0);
      set("no_sell",1);
      set("no_give",1);
      set("no_drop",1);
      set("no_get",1);
set("is_monitored", 1);
		set("material", "wood");
		set("long", "这是诸葛小花用的枪。\n");
		set("wield_msg", HIM "$N的手中突然出现一把$n"+HIM "，眼里充满了杀气。\n" NOR);
set("unwield_msg", HIM "$N手中的$n"+HIM "慢慢消失了，也不知道去那里了。\n" NOR);
	}
	init_spear(120);
	setup();
}
