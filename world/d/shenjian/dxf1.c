// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "东厢房");
        set("long", @LONG
这里是用来让来访的宾客住宿的地方，房间里一尘不染，家具
摆放的错落有秩，给人一种宾至如归的感觉。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"dxf",
]));
set("objects", ([
		__DIR__"npc/swordman" : 1,
          	]));
        set("coor/x",-1290);

	set("coor/y",255);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
