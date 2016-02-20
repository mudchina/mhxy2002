// yudi.c

#include <weapon.h>
#include <ansi.h>


inherit QIN;

void create()
{
        set_name(HIW"留香琴"NOR, ({ "liuxiang qin","liuxiang", "qin" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "架");
		set("value", 20000);
		set("material", "wood");
		set("long", "一架古色古香的七弦琴,但是已经断了两根弦。\n");
		set("wield_msg", "$N拿起一架$n放在手上轻轻弹了弹。\n");
		set("unwield_msg", "$N蓦然笑了，将$n收回腰间。\n");
	}
	init_qin(150);
	setup();
}
