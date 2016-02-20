#include <weapon.h>
#include <ansi.h>

inherit NEEDLE;

void create()
{
        set_name(HIC"仙鹤神针"NOR, ({ "xianhe needle","zhen","needle" }) );
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("value", 0);
                set("no_put",1);
                set("no_zm",1);
                set("no_give",1);
                set("material", "iron");
                set("long", WHT"上古十二神兵之一：仙鹤神针。\n"NOR);
                set("wield_msg", "$N慢慢捻起一根$n，脸上娇媚无限。\n");
        }
        init_needle(100+random(100));
        setup();
}
