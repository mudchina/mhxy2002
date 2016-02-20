//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>

#include <weapon.h>

inherit DAGGER;

void create()
{
	set_name(HIR"孽"HIC"龙"HIW"寒"HIG"匕"NOR, ({"nielong bi", "hanbi", "dagger","bi" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把稀世之宝。\n");
		set("value", 50);
		set("no_sell",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
              set("rumor_msg",1);
              set("is_monitored", 1);
		set("material", "steel");
	}
	init_dagger(50+random(50));
	set("wield_msg", YEL"$N"NOR+YEL"从怀中摸出一把$n"NOR+YEL"握在手中。\n");
	set("unwield_msg", YEL"$N"NOR+YEL"将手中的$n"NOR+YEL"藏入怀中。\n");
	setup();
}
