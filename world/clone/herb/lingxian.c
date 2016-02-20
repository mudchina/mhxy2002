// lingxian.c

#include "herb.h"

void create()
{
	set_name(MAG "ÁéÏÉ" NOR, ({ "ling xian", "herb_lingxian" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "ÕâÊÇÖĞÒ©Ò©²Ä¡£\n");
		set("base_unit", "¿é");
		set("base_value", 5000);
        	set("base_weight", 40);
	}
	setup();
}
