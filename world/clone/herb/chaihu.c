// ruxiang.c

#include "herb.h"

void create()
{
	set_name(CYN "²ñºú" NOR, ({ "chai hu", "herb_chaihu" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 4000);
        	set("weight", 60);
		set("base_unit","¿é");
	}
	setup();
}
