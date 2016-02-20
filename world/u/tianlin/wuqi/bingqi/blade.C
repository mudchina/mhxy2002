//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name(HIG"寒 "HIW"雪 "HIC"寶 "HIR"刀"NOR, ({"hanxue dao","blade","dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", HIY"这是一把陰陽怪氣的寶刀!\n"NOR);
                set("value", 200000);
                set("material", "gold");
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("wield_msg", CYN"一道血光闪过,$N"NOR+CYN"手中多了把$n"NOR+CYN"！\n"NOR);
                set("unwield_msg", CYN"$N"NOR+CYN"将$n"NOR+CYN"收回刀鞘，众人才松了口气。\n"NOR);
                set("weapon_prop/courage", 15);

        }
      init_blade(100+random(100));
      setup();
}

