// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "右花园");
        set("long", @LONG
这里是花园的右边，遍地青草，四处分放着一些石凳，石桌，还
有几个凉亭，好一个人间胜地。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
   "south" : __DIR__"rwuc",
  "east" : __DIR__"dxf",
  "west" : __DIR__"qhuayuan",
]));
 set("objects", ([
		__DIR__"npc/guard" : 2,
	]));
        set("coor/x",-1300);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
