//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(WHT "冰魄寒光剑" NOR, ({"hanguang jian", "sword", "jian", "bingpo"}));
        set_weight(10000);
                set("unit", "把");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","一把用冰打造的宝剑。\n");
                set("value", 220000);
                set("rumor_msg",1);
                set("is_monitored", 1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
	         set("wield_msg","$n"HIB"「唰」地从剑鞘中弹出，落入$N"HIB"的手中，剑尖还兀自闪个不停。\n"NOR);
	         set("unwield_msg",HIB"$N将手中的"NOR"$n"HIB"插入腰间，脸色更加阴沉了！\n"NOR);
		  set("weapon_prop/courage", 10);
        }
        init_sword(100+random(100));
        setup();
}
