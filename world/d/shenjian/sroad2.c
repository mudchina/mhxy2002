// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "枫林小路");
        set("long", @LONG
走在小石径上，你心里忽然有了种已多年未曾有过的恬适和
安静，让人不由的想到了诗，“远上寒山石径斜，白云深处有人
家，停车爱坐枫林晚，霜叶红於二月花。”
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sroad3",
  "south" : __DIR__"sroad1",
]));
          set("coor/x",-1310);

	set("coor/y",195);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
