// LLY@FYSY // waterskin.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("大酒壶", ({ "wineskin", "skin" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个大酒壶，能装很多的酒。\n");
		set("unit", "个");
		set("value", 120);
		set("max_liquid", 30);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "alcohol",
		"name": "杏花酒",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}
 