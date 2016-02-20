
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("百事可乐", ({ "bskl", "kele" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶看上去很美的百事可乐。\n");
		set("unit", "瓶");
		set("value", 400);
		set("max_liquid", 15);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "cola",
		"name": "可乐",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}

