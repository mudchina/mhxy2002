// beimu.c

#include "herb.h"

void create()
{
        set_name(HIC "±´Ä¸" NOR, ({ "bei mu", "herb_beimu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("unit", "¿é");
                set("value", 7000);
		set("base_unit","¿é");
                set("weight", 100);
        }
        setup();
}
