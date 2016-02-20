//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
              set_name( HIW "阿弥陀"HIY"禅杖" NOR, ({ "chan zhang", "zhang", "staff" }) );
	       set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
              set("unit", "条");
              set("long", HIR"这是一根攻击力极强的武器。\n"NOR);
              set("value", 300000);
              set("material", "brass");
              set("rumor_msg",1);
              set("no_sell",1);
              set("no_get",1);
              set("no_give",1);
              set("no_drop",1);
              set("is_monitored", 1);
              set("wield_msg", "$N将$n握在手中。\n");
              set("unwield_msg", "$N放下手中的$n。\n");
	}

       init_staff(100+random(100));
	setup();
}
