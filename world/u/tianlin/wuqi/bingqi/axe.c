//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
	set_name(HIR"恶魔"HIC"＊"HIR"战斧"NOR, ({ "zhan axe", "axe" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
              set("rumor_msg",1);
		set("no_sell",1);
		set("no_get",1);
		set("no_give",1);
		set("no_drop",1);
              set("is_monitored", 1);
		set("material", "steel");
		set("long", "这是一把沉重的"HIC"恶魔"HIC"＊"HIC"战斧"NOR"，砍起东西来非常顺手。\n");
		set("value", 500);
		set("wield_msg", "$N拿出一把$n，握在手中心中直说果然是神斧啊。\n");
		set("unwield_msg", "$N放下手中的$n,慢慢的松了口气。\n");
	}
	init_axe(100+random(100), TWO_HANDED);
	setup();
}
