
// 神话世界·西游记·版本４．５０
#include <ansi.h>
/* <SecCrypt CPL V3R05> */
 
//feiyu

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name(HIR"凤凰翎"NOR, ({ "fenghuang ling","ling" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",HIR"这是火凤凰身上的羽毛，上面燃烧着火焰。\n"NOR);
                set("unit", "些");
                set("base_unit", "枝");
                set("base_weight", 40);
                       set("value", 20000);
                set("base_value", 50);
        }
        set_amount(30);
        init_throwing(100);
        setup();
}


