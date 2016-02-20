// bohe

#include "herb.h"

void create()
{
        set_name( HIC"±¡ºÉ" NOR, ({ "bo he", "herb_bohe" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("base_unit", "Æ¿");
                set("unit","Æ¿");
                set("value", 5000);
                set("weight", 50);
        }
        setup();
}
