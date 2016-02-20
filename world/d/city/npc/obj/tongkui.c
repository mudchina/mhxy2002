// huyao.c

#include <armor.h>

inherit HEAD;

void create()
{
	set_name("铜盔" , ({"tong kui","tongkui","kui"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "顶");
                set("long", "这是一顶青铜制成的头盔，用以保护头部。\n");
	set("value",1000);
		set("oldsix/max_damage",20);
		set("oldsix/protect",3);
		set("material", "tong");
		set("armor_prop/armor", 8);
	}
	setup();
}
