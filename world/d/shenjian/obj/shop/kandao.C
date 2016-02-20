#include <weapon.h>
#include <ansi.h>;

inherit BLADE;

void create()
{
        set_name("砍刀", ({"damo dao","blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
           set("long", HIY"这是一把杀人用的刀\n"NOR);
    set("value", 100000);
                set("material", "gold");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
          set("unwield_msg", "$N将手中的$n插入刀鞘。\n");
        set("weapon_prop/courage", 15);

        }
      init_blade(80);
        setup();
}

