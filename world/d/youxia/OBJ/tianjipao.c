// cloth.c
//created 17-06-2001 海上飘(piao)


#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW "天机袍" NOR, ({ "tianji cloth","tianji","cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是天机老人身穿的白袍。\n");
		set("value", 10000);
		set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 80);
                set("armor_prop/dodge", 20);
                set("armor_prop/spells", 15);
	}
	setup();
}
