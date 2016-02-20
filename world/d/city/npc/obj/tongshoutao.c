// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit HANDS;

void create()
{
	set_name("铜手套",({"tong shoutao","tongshoutao","shoutao"}));
	set_weight(800);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","双");
		set("material","tong");
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("long", "这是一双青铜制成的手套，用来保护双手。\n");
		set("armor_prop/armor",8);
		set("value",1000);
	}
	setup();
}
