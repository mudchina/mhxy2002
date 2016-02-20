// taoxian.c

#include "herb.h"

void create()
{
	set_name(MAG "ÌÒÏÉ" NOR, ({ "tao xian", "herb_taoxian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖĞÒ©Ò©²Ä¡£\n");
		set("unit", "¿é");
		set("value", 5000);
        	set("weight", 40);
set("base_unit","¿é");
	}
	setup();
}
