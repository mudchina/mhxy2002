// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "厨房");
        set("long", @LONG
一缕缕香气从火炉上的大铁锅中飘出，房间里到处摆着各式各样的菜肴。
神剑山庄人丁众多，每天要吃的东西都是从这里出去的。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lpt",
]));
set("objects", ([
		__DIR__"npc/cook" : 2,
          	]));
                set("coor/x",-1330);

	set("coor/y",260);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
