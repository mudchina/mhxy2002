// lurong.c

#include "herb.h"

void create()
{
	set_name(HIY "Â¹È×" NOR, ({ "lurong", "herb_lurong" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 10000);
        	set("weight", 70);
set("base_unit","¿é");
	}
	setup();
}
