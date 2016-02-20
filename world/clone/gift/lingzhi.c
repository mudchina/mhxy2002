// lingzhi.c 万年灵芝
//本来是lywin改的原码,他做的是加武学和潜能的我看了一下,灵芝应该是加法力的,所以我做了点改动.(xixi)
//by tianlin 2001/5/1

#include <ansi.h>
inherit ITEM;


void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIC"万年灵芝"NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵武林人士梦寐以求的万年灵芝，据说吃了可得到一定的法力修为。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("max_mana", 100);
	this_player()->add("mana",300);
	message_vision("$N吃下一棵万年灵芝，好象发现自己的法力又强大许多 !\n", this_player());
	destruct(this_object());
	return 1;
}

