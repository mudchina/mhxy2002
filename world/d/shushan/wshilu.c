// wshilu.c 石板路 by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIG "石板路" HIR "」" NOR);
	set("long", @LONG
你走在一条石板路上，从这里往西是饭厅，你看见有不少人
围在青儿身边。向南走就是通往后山的路。
LONG
	);
       set("exits", ([
		"south" : __DIR__"changlang4",
		 "east" : __DIR__"wshilu1",
               "west" : __DIR__"fanting",
            "northup" :  __DIR__"houshan",
		]));
             set("objects", 
        ([ //sizeof() == 1
               "d/shushan/npc/mingyue" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "northup" ) {
        if (objectp(present("ming yue", environment(me))))
        return notify_fail("明月亮出手中的青锋剑，说道:师傅有领,闲杂人请勿上后山!\n");
        }   
        return ::valid_leave(me, dir);
}


