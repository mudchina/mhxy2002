// chansu.c

#include "herb.h"

void create()
{
        set_name(HIW "ó¸ËÖ" NOR, ({ "chansu", "herb_chansu" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("unit", "¶ä");
                set("value", 1000);
                set("weight", 20);
		set("base_unit","¿é");
        }
        setup();
}
