

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("水果面包", ({ "fruitbread" }) );
	set_weight(40);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个看上去很不错的水果面包。\n");
		set("unit", "个");
		set("value", 200);
		set("food_remaining", 4);
		set("food_supply", 60);
	}
}

