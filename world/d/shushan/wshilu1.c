// wshilu.c 石板路 by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIG "石板路" HIR "」" NOR);
	set("long", @LONG
你走在一条石板路上，从这里往西是饭厅，你看见有不少人
围在青儿身边。从那边过来，东面是蜀山派大厅。
LONG
	);
       set("exits", ([
		"west" : __DIR__"wshilu",
	        "eastup" : __DIR__"dating",
         ]));
        setup();
	replace_program(ROOM);
}

