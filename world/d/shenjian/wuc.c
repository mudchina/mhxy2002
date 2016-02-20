// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "武场中央");
        set("long", @LONG
这个练武场非常的大，可以看出神剑山庄与众不同的地方，场地
是用细砂铺成，神剑山庄的弟子们正在专心的练着功夫。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qhuayuan",
  "south" : __DIR__"rroad",
    "east" : __DIR__"rwuc",
    "west" : __DIR__"lwuc",
]));
     set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard1" : 1,
                  __DIR__"npc/guard2" : 1,
                  __DIR__"npc/zhen" : 1,
	]));
  set("outdoors", __DIR__);
	setup();
}
