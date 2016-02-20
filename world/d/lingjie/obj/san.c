// unbrella by LitChi

#include <ansi.h>
#include <weapon.h>

inherit UMBRELLA;

void create()
{
	set_name(HIC"灵幡伞"NOR, ({ "umbrella", "san" }) );
	set_weight(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把具有灵界之气的伞。\n");
		set("value", 90000);
		set("material", "crimsonsteel");
	}
	init_umbrella(100);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声把$n打开握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入身后。\n");

// The setup() is required.

	setup();
}
