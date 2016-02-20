
#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{
        set_name(HIG "柳树枝" NOR, ({"liushu zhi", "zhi", "sword"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 10);
                set("material", "wood");
                set("long", "这是一根普普通通的柳树枝，剑法高强之人可将其当剑使用．\n");
                set("wield_msg", "$N抽出一根$n握在手中。\n");
                set("unequip_msg", "$N将手中的$n放了起来．\n");
        }
        init_sword(300);
        setup();
}

