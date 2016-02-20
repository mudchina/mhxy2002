#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(HIM"情丝"NOR, ({"qing si","whip"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",YEL"上古十二神兵之一：情丝\n"NOR);
                set("unit", "条");
                set("no_put",1);
                set("value", 0);
                set("no_zm",1);
                set("no_give",1);

        }
        init_whip(100+random(100));
        setup();
}
