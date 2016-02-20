// man-shoe.c
 
#include <armor.h>
 
inherit BOOTS;
 
void create()
{
	set_name("铜靴", ({ "tong xue", "tongxue","xue" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "tong");
		set("unit", "双");
		set("long", "这是一双青铜制作的靴子，用以保护双脚。\n");
		set("value", 2000);
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("armor_prop/dodge", -3);
		set("armor_prop/armor", 4);
	}
	setup();
}
