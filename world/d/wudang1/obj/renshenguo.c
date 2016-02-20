// renshenguo.c
inherit ITEM;
#include <ansi.h>

void init()
{
	add_action("do_eat", "eat");
	remove_call_out("destguo");
	call_out("destguo", 10);
}
void destguo()
{
	message_vision("$N慢慢渗出水来，一会就腐烂掉了。\n",this_object());
	destruct(this_object());
}

void create()
{
	set_name(HIR"人参果"NOR, ({"guo", "renshen guo"}));
	set("unit", "朵");
	set("long", "这是一只人参果, 已经成型, 真的象极了三周不满的小孩。\n");
	setup();
}

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="guo")
	{
		me->add("max_force",10);
		me->set("force",me->query("max_force"));
		me->set("eff_kee",me->query("max_kee"));
		me->set("kee",me->query("eff_kee"));
                message_vision("$N吃下一枚人参果，只觉得精神健旺，气血充盈，体内真力源源滋生，甚至不再感到饥饿干渴!\n",me);

		destruct(this_object());
	}
	return 1;
}
