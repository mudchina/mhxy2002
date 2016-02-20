// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "武场");
        set("long", @LONG
一排一排的梅花桩竖立在场地的中央，几个弟子正专心
的练习着轻功和步法等下盘功夫。从这里可以看到西边的武
场几缕剑光在阳光下飞舞扇动。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"nans",
  "west" : __DIR__"wuc",
  "north" : __DIR__"rqhuayuan",
]));
         set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard1" : 3,
	]));
        set("coor/x",-1300);

	set("coor/y",240);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
