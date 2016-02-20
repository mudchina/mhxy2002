// edit by lucas

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("河豚", ({ "hetun", "fish" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一条剧毒的河豚鱼，虽然很美味，但你敢吃吗？\n");
                set("unit", "条");
                set("food_remaining", 4);
                set("food_supply", 15);
        }
        setup();
}


