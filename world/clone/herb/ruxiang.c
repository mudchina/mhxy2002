// ruxiang.c

#include "herb.h"

void create()
{
	set_name(HIW "ÈéÏã" NOR, ({ "ru xiang", "herb_ruxiang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖĞÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 500);
        	set("weight", 50);
set("base_unit","¿é");
	}
	setup();
}
