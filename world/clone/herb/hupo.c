// hupo.c

#include "herb.h"

void create()
{
        set_name(HIY "çúçê" NOR, ({ "hupo", "herb_hupo" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("unit", "¿é");
                set("value", 900);
                set("weight", 20);
set("base_unit","¿é");
        }
        setup();
}
