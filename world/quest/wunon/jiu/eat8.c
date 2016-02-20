// wineskin.c  酒袋

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("茅台酒", ({"jiu8",}));
	set_weight(30000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个用来装酒的大酒袋，大概装得八、九升的酒。\n");
		set("unit", "壶");
		set("no_drop","不要乱丢，这东西打到人痛！\n");
		set("no_get",1);
		set("no_give",1);
		set("no_steal",1);

		set("value", 10000);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "茅台酒",
		"remaining": 15,
		"drunk_supply": 6,
	]));
}

