//stick.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit STICK;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW "天机"NOR +HIC"棍"NOR, ({"tianji gun", "gun"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把发着青色光茫的短棒，传说是"+HIC"天机老人"NOR+"曾用过的武器。\n");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("material", "steel");
                set("is_monitored", 1);
                set("wield_msg", HIW"$N从背后小心冀冀地拿出了一根短棍，仔细一看，竟是传说中的$n"+HIW"。\n"NOR);
                set("unwield_msg",HIW "$N暗暗地吐了一口气，收起了这恐怖的$n。\n");
        }
        init_stick(120);
        setup();
}

