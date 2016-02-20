#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
        set_name(HIG "Îå¹É¸Ö²æ" NOR, ({ "steel fork", "cha", "fork"}) );
        set_weight(10000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "°Ñ");
                set("value", 0);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);
                set("material", "blacksteel");
                set("treasure",1);
}
        init_fork(40);

        setup();
}
