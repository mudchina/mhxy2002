// hantie-kuang2.c 千年寒铁  
// 星星lywin 2000/8/27

#include <ansi.h>
inherit ITEM;  
void create() 
{
        set_name(HIR"千年寒铁"NOR,({"han tie", "kuang"}));
        set_weight(50000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("no_put",1);
                set("long", "这是一块沉重的寒铁矿石。\n");
             }
        setup();
}
