// chenpi.c

#include "herb.h"

void create()
{
	set_name(YEL "³ÂÆ¤" NOR, ({ "chenpi", "herb_chenpi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 10);
        	set("weight", 20);
set("base_unit","¿é");
	}
	setup();
}
