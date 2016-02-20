// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "前花园");
        set("long", @LONG
这里是山庄前院的花园中央，适逢菊花盛开的时节，满地的菊花
争奇斗艳，竞相开放，左右不断的有侍女来来去去。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dt",
  "south" : __DIR__"wuc",
   "east" : __DIR__"rqhuayuan",
    "west" : __DIR__"lqhuayuan",
]));
      set("objects", ([
		__DIR__"npc/shinu" : 2,
	]));
              set("coor/x",-1310);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
