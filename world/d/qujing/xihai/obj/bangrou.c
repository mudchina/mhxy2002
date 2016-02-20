// edit by lucas

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("蚌肉", ({ "bangrou", "rou" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "鲜美可口的蚌肉。\n");
                set("unit", "条");
                set("food_remaining", 4);
                set("food_supply", 15);
        }
        setup();
}

