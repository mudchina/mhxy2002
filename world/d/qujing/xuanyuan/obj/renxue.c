// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

inherit ITEM;
#include <ansi.h>
inherit F_FOOD;

void create()
{
       set_name(HIR"鲜血"NOR ,({"xian xue","xue"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                 set("long", "一碗鲜红的鲜血.\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 60);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "江米酒",
                "drunk_apply": 10,
        ]));
}
