// dating.c 大厅 by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIY "大厅" HIR "」" NOR);
	set("long", @LONG
 这里是蜀山派大厅，正中靠北摆着一张八仙桌，桌上供着蜀山派剑圣的神位，
旁边放着两个青瓷花瓶，插着几支孔雀翎，墙上写着两个字“蜀山派”。
LONG
	);
        set("no_sleep_room","1");
        set("exits", ([
	      "westdown" : __DIR__"wshilu1",
	      "eastdown" : __DIR__"eshilu",
            "southdown" : __DIR__"dadian",
               ]));


	set("objects", ([
		__DIR__"npc/jiujianxian" : 1,
              __DIR__"npc/dizi" : 2,
              __DIR__"npc/dizi1" : 2,
       ]));
       setup();
	replace_program(ROOM);
}



       