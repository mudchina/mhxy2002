// edit by lucas
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("虾仁", ({ "xiaren", "ren" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块美味可口的虾仁。\n");
                set("unit", "块");
                set("food_remaining", 8);
                set("food_supply", 30);
        }
        setup();
}

