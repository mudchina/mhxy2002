// umbrella.c

#include <ansi.h>;
#include <weapon.h>

inherit UMBRELLA;

void create()
{
        set_name(HIR"无量神伞"NOR, ({"umbrella", "san"}) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "把");
		set("value", 500);
		set("material", "iron");
                set("long", HIW"这是一把威力非同小可的神伞。NOR,\n");
                set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n插入腰间的伞套。\n");
	}
        init_umbrella(80);
	setup();
}
