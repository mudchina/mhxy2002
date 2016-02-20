// pofengblade.c

#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(CYN"破风斩" NOR, ({ "pofeng blade", "pofengblade","dao", "blade" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
        set("value", 30000);
      
    set("no_give","这个人想要，你让他和红雨说嘛，他不说红雨怎么知道他想要呢？\n");
                set("material", "gold");
                set("no_drop", "破风斩是宝物，你怎么能乱扔呢？砸到小朋友怎么办？就算砸不到小朋友，砸到花花草草也不好嘛！\n");
                
                set("long", "超级兵器之一，陷空奇侠红雨当年所用，传说其锋利连风都能切开，所以叫“破风斩”。\n");
                set("wield_msg", "$N大喝一声：红雨助我！却见霞光一闪，掌中忽然多出一柄$n。\n");
                set("unwield_msg", "$N大喝一声：走！$n在$N掌中霞光一闪，忽然不见了。\n");
        }
        init_blade(180);
        setup();
}

