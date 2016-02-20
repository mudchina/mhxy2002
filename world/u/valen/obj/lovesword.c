#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
            set_name(HIC"郎情"HIR"妾意"NOR"剑", ({"love sword", "sword"}));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把青色的长剑，看起来异常华丽．\n");
                set("value", 0);
                set("material", "crimsonsteel");
                set("wield_msg",
    "$N「唰」地一声抽出一把$n握在手中．不禁回想起和昔日恋人在一起的幸福时光.\n");
                set("unwield_msg",
    "$N将手中的$n插入腰间，眼角流露出一丝哀怨．\n");
          set("weapon_prop/cor", 10);
        }
            init_sword(110);
        setup();
}
