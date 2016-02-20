//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit FORK;

void create()
{
       set_name(HIB"九天"HIY"轩骨"HIG"叉"NOR, ({ "xuangu fork", "fork", "cha"}) );
       set_weight(8000);
       if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 200000);
                set("rumor_msg",1);
                set("no_sell",1);
                set("no_get",1);
                set("no_give",1);
	         set("no_drop",1);
                set("is_monitored", 1);
                set("material", "iron");
                set("long", HIW"这是由龙筋虎骨制作而成的叉子。\n"NOR);
                set("wield_msg", "$N抄起一柄$n轻轻的握在手里。\n");
        }
        init_fork(100+random(100));
        setup();
}

