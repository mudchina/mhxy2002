//changlang3.c by yuahu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
	set ("short",HIR "「" HIY "长廊" HIR "」" NOR);
	set ("long", @LONG

这是个长廊，北面是蜀山派内的物品房，要在蜀山派做杂事的人都得去
物品房领工具，南边是东练武场。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"north" : __DIR__"xiuxishi",
		"south" : __DIR__"wupinfang",
	]));

	setup();
}
