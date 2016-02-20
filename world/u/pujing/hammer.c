//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name(HIW"九骨开山锤"NOR, ({"jiugu chui","jiugu","chui","kaishan chui","hammer"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一个九千多吨重的铁锤。\n");
                set("value", 300000);
                set("material", "iron");
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
                set("no_drop",1);
                set("is_monitored", 1);
                set("wield_msg", HIB"$N双手虚划，$n"HIB"流向双手，已然握住。\n"NOR);
                set("unwield_msg", HIB"$N将$n"HIB"收回背后。\n"NOR);
        }
        init_hammer(100+random(100));
        setup();
}
