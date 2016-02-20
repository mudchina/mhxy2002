// eshilu.c 石板路 by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIG "石板路" HIR "」" NOR);
	set("long", @LONG
你走在一条石板路上，从这里往东是物品房，你看见有不少人
在那里跟鹤儿学功夫，从那边过来，西面是蜀山派大厅。
LONG
	);
       set("exits", ([
		"westup" : __DIR__"dating",
		 "east" : __DIR__"wupinfang",
		]));
        setup();
	replace_program(ROOM);
}

