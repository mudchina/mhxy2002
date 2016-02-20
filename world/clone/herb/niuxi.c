// niuqi.c

#include "herb.h"

void create()
{
	set_name(CYN "Å£Ï¥" NOR, ({ "niu xi", "herb_niuxi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 2000);
        	set("weight", 50);
set("base_unit","¿é");
	}
	setup();
}
