// LLY@FYSY 
// cloth.c
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
         set_name("剑神青衫", ({ "sjcloth"}) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
        	set("long", "这是神剑山庄中地位极高之人才能穿戴的衣物,穿着它就能说明在江湖中的地位之崇高。\n");
		set("material", "cloth");
		set("armor_prop/armor", 40);
	}
	setup();
}
