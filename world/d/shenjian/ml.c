// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "马廊");
        set("long", @LONG
来到这里，只听到一阵阵的马叫声，一匹匹健马栓在马房里，
由此可见庄中每日来的宾客数目了。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"lwuc",
  "east" : __DIR__"rroad",
]));
 set("objects", ([
		__DIR__"npc/mafu" : 2,
             	]));
        set("coor/x",-1320);

	set("coor/y",230);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
