//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","西武场");
	set("long", @LONG

这是露天练武场，好多人在这里辛苦的练着，你走在场中，没有人
回头看你一眼，都在聚精汇神的练着自己的功夫。
LONG);
        set("outdoors", 2);
        set("exits", ([
	    "east" : __DIR__"yongdao",
   	]));
        set("objects", ([ 
             __DIR__"obj/muren" : 4,
             __DIR__"npc/dizi" : 1,
             __DIR__"npc/dizi1" : 1,
       ]));
        setup();
}

