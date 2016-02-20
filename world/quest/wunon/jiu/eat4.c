// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("女儿红", ({"jiu4",}));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "壶");
		set("value", 2000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "女儿红",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

