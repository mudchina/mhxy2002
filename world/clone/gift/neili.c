// lingzhi.c 千年雪莲
//星星(lywin)2000/4/22
//by tianlin 2001/5/1

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name(HIR"万年雪莲"NOR, ({"xue lian", "lian"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵武林人士梦寐以求的万年雪莲，据说吃了之后,可以提升内力的修为。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("max_force", 100);
	this_player()->add("eff_force", 100);
	message_vision("$N吃下一棵万年雪莲，突然你觉着体力好象有几道真气在体内横冲直撞好一会才恢复过来 !\n", this_player());
	destruct(this_object());
	return 1;
}

