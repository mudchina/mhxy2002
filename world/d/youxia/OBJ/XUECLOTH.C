// created 17-06-2001 海上飘(piao)


#include <armor.h>
#include <ansi.h>

inherit CLOTH;
void create()
{
	set_name(HIW"寒天冰衣"NOR, ({ "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 60);
	}
	setup();
}
