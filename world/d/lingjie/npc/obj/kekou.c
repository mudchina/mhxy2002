

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("可口可乐", ({ "cocacola", "kele" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一瓶不一定可口的可口可乐。\n");
		set("unit", "瓶");
		set("value", 400);
		set("max_liquid", 15);
	}

		set("liquid", ([
		"type": "cola",
		"name": "可乐",
		"remaining": 15,
		"drunk_apply": 6,
	]) );
}

