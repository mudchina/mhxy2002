// by mhsj@gslxz 2001/3/12

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(BLINK+HIC "王者之━╋━━━━━→" NOR, ({"wangzhe sword", "sword", "jian",
   "jueqing"}));
        set_weight(10000);
                set("unit", "把");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把镇妖降魔的宝剑。\n");
set("value", 220000);
		set("wield_msg",
""HIW"$N"HIC"「唰」"NOR"地一声从剑鞘中拔出$n,"HIW"$N"NOR"的脸上却透露出伤感的神情。\n");
		set("unwield_msg",
""HIW"$N"NOR"将手中的$n插入腰间，神情更加忧伤了！\n");
                set("weapon_prop/courage", 10);
        }
    init_sword(30);
        setup();
}
