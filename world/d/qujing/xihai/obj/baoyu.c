// edit by lucas
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("鲍鱼", ({ "baoyu", "fish" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一条被烹饪得香喷喷的鲍鱼。\n");
                set("unit", "条");
                set("food_remaining", 8);
                set("food_supply", 30);
        }
        setup();
}

