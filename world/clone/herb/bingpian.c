// bingpian.c

#include "herb.h"

void create()
{
        set_name(HIW "±ùÆ¬" NOR, ({ "bingpian", "herb_bingpian" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("unit","¿é");
                set("base_unit", "¿é");
                set("value", 7000);
                set("weight", 100);
        }
        setup();
}
