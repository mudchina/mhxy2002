// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "左偏厅");
        set("long", @LONG
这里是专门招待来访宾客用膳的地方，一张大理石打磨的大桌
摆在厅中，桌上放着几个玉杯，刚沏的香茗还透过杯盖冒着热气。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"dt",
  "west" : __DIR__"cf",
]));
set("objects", ([
		__DIR__"npc/guard" : 2,
          	]));
               set("coor/x",-1320);

	set("coor/y",260);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
