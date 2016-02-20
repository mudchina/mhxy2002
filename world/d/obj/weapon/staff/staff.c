// budd_staff.c
//by tianlin 2001/5/1

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIY "金刚禅杖" NOR, ({ "jingang chanzhang", "staff" , "chanzhang" }) );
	set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "这是不戒大师随身的禅仗,经过七七四十九天而做成的.\n");
		set("value", 10000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N费了好大的劲才提起这根禅仗。\n\n" NOR);
		set("unwield_msg", HIY "\n$N放下手中的金刚禅杖，觉着轻快多了.\n\n" NOR);

	}

	init_staff(80);
	setup();
}
