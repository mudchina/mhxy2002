// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "左花园");
        set("long", @LONG
随着一阵阵菊香，一座假山出现在眼前,假山顶部一缕清泉流下，
发出叮咚的声音，让人心旷神怡。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"lwuc",
    "east" : __DIR__"qhuayuan",
  "west" : __DIR__"xxf",
]));
         set("objects", ([
		__DIR__"npc/shinu" : 1,
                __DIR__"npc/guard" : 2,
	]));
        set("coor/x",-1320);

	set("coor/y",250);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
