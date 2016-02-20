// xuelian.c

#include "herb.h"

void create()
{
	set_name(HIW "Ñ©Á«" NOR, ({ "xuelian", "herb_xuelian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¶ä");
		set("value", 30000);
        	set("weight", 40);
set("base_unit","¶ä");
	}
	setup();
}
