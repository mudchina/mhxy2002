//shushan2 by yushu@SHXY 2000.12
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("七星剑", ({"qixing sword", "sword", "jian",
"qixing"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把五颜六色的宝剑。\n");
                set("unit", "把");
		set("wield_msg",
"一把五颜六色的$n从剑鞘中弹出，落到落入$N的手中。\n");
		set("unwield_msg",
"$N将手中的$n插入腰间，脸上露出一丝笑意！\n");
              set("value",12000);
		set("weapon_prop/courage", 10);
        }
        init_sword(60);
        setup();
}
