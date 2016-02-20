// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "庄外小路");
        set("long", @LONG
走出了枫林，再往前就是神剑山庄了，神剑山庄依山临水，建
筑古老而宏大。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sjsz",
  "south" : __DIR__"sroad2",
]));
          set("coor/x",-1310);

	set("coor/y",210);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
