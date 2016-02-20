// fanting.c 饭厅 by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIR "「" HIY "饭厅" HIR "」" NOR);
	set("long", @LONG
这里是蜀山派的饭厅,东西面是通往蜀山派大厅的路，看起来这
里有很多好吃的。很多人围着青儿让他做好吃的呢。你可以要
些(yao)吃的。

LONG
	);
        
       set("no_fight",1);
             set("exits", ([
	      "east" : __DIR__"wshilu",
	]));

        set("objects", ([ /* sizeof() == 2 */
        __DIR__"npc/qinger" : 1,
        __DIR__"npc/dizi1" : 1,
        __DIR__"npc/dizi" : 1,
        "/d/ourhome/obj/hulu" :1,
        ]));
       set("clean_up", 1);
       set("resource", ([ /* sizeof() == 1 */
       "water" : 1,
       ]));

      setup();
}
int valid_leave()
{
       if((present("gongbao jiding", this_player())))
            return notify_fail("吃完宫保鸡丁再走吗！\n");
            if((present("hulu", this_player())))
            return notify_fail("你不能把葫芦带走！\n");
             return ::valid_leave();
}


