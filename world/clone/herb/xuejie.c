// xuejie.c

#include "herb.h"

void create()
{
	set_name(RED "Ñª½ß" NOR, ({ "xuejie", "herb_xuejie" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 200);
        	set("weight", 40);
set("base_unit","¿é");
	}
	setup();
}
