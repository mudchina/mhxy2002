// bamboo_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("树枝", ({ "shuzhi", "zhi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
		set("value", 200);
                set("material", "bamboo");
                set("long", 
"这是一根树枝，小孩子们喜欢拿在手中用来打打闹闹。\n");
                set("wield_msg", "$N拿出一根$n，握在手中。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_sword(15);
        setup();
}
 
