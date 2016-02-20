//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIR "血玉龙筋鞭" NOR, ({"xueyu bian","whip","bian"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",HIG"此鞭有无法无天之功力\n"NOR);
                set("unit", "条");
                set("value", 200000);
		  set("no_sell",1);
		  set("no_get",1);
		  set("no_give",1);
		  set("no_drop",1);
                set("rumor_msg",1);
                set("is_monitored", 1);
                set("wield_msg", HIW"$N将$n"HIW"自腰间解开，周围众人耳中顿时充斥着阵阵凄号。\n"NOR);
                set("unwield_msg", HIW"$N将$n"HIW"盘回腰上，一切又恢复了正常。\n"NOR);
        }
        init_whip(100+random(100));
        setup();
}

