// dagger.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
          set_name("无常爪", ({"zhua"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                 set("unit", "只");
                 set("long", "这是一只铁爪，发着暗绿色的光芒，似乎还有其它作用。\n");
		set("value", 50);
		set("material", "steel");
	}
          init_dagger(88);

// These properties are optional, if you don't set them, it will use the
// default values.

          set("wield_msg", "$N将双手迎风一晃，只见绿光一闪，$n已在$N掌中。\n");
          set("unwield_msg", "$N将双手迎风一晃，只见绿光一黯，$n已经不见。\n");

// The setup() is required.

	setup();
}
