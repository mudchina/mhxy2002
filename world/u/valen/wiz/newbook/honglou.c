#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC"红楼梦"NOR, ({ "honglou", "book"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "本");
                set("long","四大名著之一。\n");
                set("value", 1500000);
                set("material", "paper");
                set("skill",
                ([
                        "name": "literate",
                        "exp_required": 10,
                        "jing_cost":    10,
                        "difficulty":   15,
                        "max_skill":    120,
                        "min_skill":    100,
                ]) );
        }
}

