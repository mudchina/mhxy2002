//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name(HIC"璇 "HIW"天"HIG" 棒"NOR, ({"xuantian bang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("rumor_msg",1);
                set("is_monitored", 1);
                set("long", HIG"威力巨大的棒。\n"NOR);
                set("value", 170000);
                set("material", "steel");
                set("wield_msg", MAG"$N"NOR+MAG"「呼」地一声抽出一把$n"NOR+MAG"拿在手里还转了两圈。\n"NOR);
                set("unwield_msg", MAG"$N"NOR+MAG"放下手中的$n"NOR+MAG",觉着身体轻快多了。\n"NOR);
        }
        init_stick(100+random(100));
        setup();
}

