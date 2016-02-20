// wupinfang.c 物品房 by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIY "物品房" HIR "」" NOR);
	set("long", @LONG
这是物品房，一个大架子。上面放的整整齐齐，看来这里的管家是
很认真负责的，一些人正在跟管物品工具的管家说着什么。
LONG
	);
        set("no_fight",1);
        set("exits", ([
		"north": __DIR__"changlang3",
		"west" : __DIR__"eshilu",
		"south": __DIR__"changlang2",

		]));


	set("objects", ([
		__DIR__"npc/heer" : 1,
              __DIR__"npc/dizi" : 1,
              __DIR__"npc/dizi1" : 1,
             ]));


       setup();
	replace_program(ROOM);
}

