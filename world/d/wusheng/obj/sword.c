// wusheng-sword.c 纯阳宝剑

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit SWORD;

void create()
{
        set_name(HIW"纯阳宝剑"NOR, ({"chunyang sword", "baojian", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把无剑身的宝剑，泛着点点灵光。\n");
		set("no_sell", 1);
		set("no_drop", 1);
		set("no_put", 1);
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N冷笑一声，从背后拔出了$n。用灵气一逼，现出玄光剑身。\n");
                set("unwield_msg", "$N将手中的$n插回鞘中，嘴角多了一丝笑意。\n");
                set("weapon_prop/int", 50);

        }
        init_sword(120);
        setup();
}

