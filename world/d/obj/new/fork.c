// gangcha.c
//create by lixin

#include <weapon.h>
#include <ansi.h>
inherit FORK;
//inherit F_UNIQUE; 

void create()
{
        set_name(BLINK HIW"龙神"NOR+HIC"叉"NOR, ({ "long cha", "cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 0);
                set("no_sell",1);
                set("no_give",1);
                set("no_drop",1);
                set("no_get",1);
                set("is_monitored", 1);
                set("material", "iron");
                set("long", "一柄钢叉。\n");
                set("wield_msg", HIY"$N随手拿了一柄$n"NOR+HIY"，叉尖还闪着冷光。\n"NOR);
                set("unwield_msg", HIY "$N用罢$n" NOR+HIY"，反手背到了背后。\n");
            }        
init_fork(120);
        setup();
}

