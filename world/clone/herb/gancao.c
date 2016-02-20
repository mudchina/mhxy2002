// gancao.c

#include "herb.h"

void create()
{
        set_name( RED"¸Ê²Ý" NOR, ({ "gan cao", "herb_gancao" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("unit", "¿Å");
                set("value", 500);
                set("weight", 60);
set("base_unit","¿Å");
        }
        setup();
}
