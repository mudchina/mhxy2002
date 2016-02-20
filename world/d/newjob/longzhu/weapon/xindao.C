// 心叶刀 by Calvin

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIC"心叶刀"NOR, ({"xinye dao", "dao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把紫色的心叶形刀,是传说中心叶童子的宝物。\n");
                set("value", 10000);
                set("material", "gold");
                set("wield_msg", MAG"$N念动口诀,「唰」地一声飞出一把$n"NOR+MAG"握在手中,狂风四起,闪电齐鸣\n"NOR);
                set("unwield_msg", MAG"$N念动口诀,面前空悬的$n"NOR+MAG"慢慢化为一道青光消失了。\n"NOR);
        set("weapon_prop/courage", 120);
        }
        init_blade(50);
        setup();
}
