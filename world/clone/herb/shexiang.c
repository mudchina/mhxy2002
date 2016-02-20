// shexiang.c

#include "herb.h"

void create()
{
        set_name(YEL "÷êÏã" NOR, ({ "she xiang", "herb_shexiang" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÖÐÒ©Ò©²Ä¡£\n");
                set("unit", "Æ¬");
                set("value", 2000);
                set("weight", 60);
set("base_unit","Æ¬");
        }
        setup();
}
