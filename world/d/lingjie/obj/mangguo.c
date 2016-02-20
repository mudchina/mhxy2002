inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("芒果", ({ "mang guo","guo"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("prep", "on");
                set("unit", "个");
                set("long", "一个青绿色肯定不大好吃的果子。\n");
                set("value", 1);
		set("food_remaining", 1);
		set("food_supply", 100);
        }
}  
