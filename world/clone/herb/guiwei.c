// guiwei.c

#include "herb.h"

void create()
{
	set_name(WHT "¹éÎ²" NOR, ({ "gui wei", "herb_guiwei" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖĞÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 3000);
        	set("weight", 50);
set("base_unit","¿é");
	}
	setup();
}
