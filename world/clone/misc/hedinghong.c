// Pill: hedinghong.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"º×¶¥ºì"NOR, ({"heding hong", "hong"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»Æ¿¾ç¶¾µÄ¶¾Ò©, Èç¹ûÓÃÀ´Á¶°µÆ÷ÓÐ¼ûÑª·âºíÖ®Ð§. \n");
		set("unit", "Æ¿");
		set("value", 20000);
	}
	setup();
}

int init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
	if(arg=="hong" || arg=="heding hong") 
	{
		message_vision("$NÑöÍ·¹¾à½¹¾à½¹àÏÂÒ»Æ¿" + name() + "¡£\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
