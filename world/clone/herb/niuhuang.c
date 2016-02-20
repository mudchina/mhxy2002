// niuhuang.c

#include "herb.h"

void create()
{
	set_name(HIY "Å£»Æ" NOR, ({ "niu huang", "herb_niuhuang" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
		set("unit", "¿Å");
		set("value", 1000);
        	set("weight", 60);
set("base_unit","¿Å");
	}
	setup();
}
