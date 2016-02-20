//shushan2 by yushu 2000.12
#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("无影神针", ({"wuying shenzhen", "shenzhen", "zhen"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("base_unit", "根");
                set("long",    "一把细小的无影神针，好像带着剧毒。\n");
                set("base_weight", 5);
                set("value",10000);
        }
        set_amount(random(10)+1);
        init_throwing(40);
        setup();
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        if( damage_bonus < 0 ) return 0;
   victim->apply_condition("shenzhen_poison", 3);
   message_vision("$N中了无影神针上的剧毒！\n", victim);
}

