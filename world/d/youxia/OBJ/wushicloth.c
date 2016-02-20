// cloth.c
//created 17-06-2001 海上飘(piao)


#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW "武士白袍" NOR, ({ "whitecloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "这是件只有武功极高的武士才可以穿的白袍。\n");
		set("value", 10000);
		set("material", "cloth");
		set("armor_prop/armor", 60);
	}
	setup();
}
