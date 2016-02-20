// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "居室");
        set("long", @LONG
这里是庄中侍女门寝息起居的地方，到处充满了欢歌笑语。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lwuc",
]));
set("objects", ([
		__DIR__"npc/shinu" : 2,
          	]));
        set("coor/x",-1330);

	set("coor/y",240);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
