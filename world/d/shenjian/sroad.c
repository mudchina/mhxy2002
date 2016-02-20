// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "枫林小路");
        set("long", @LONG
夕阳虽已消失，山坡上的枫叶却还是艳丽的，夹道的枫林中
，有一条小小的石径。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sroad1",
  "southdown" : __DIR__"hsp",
]));
         set("coor/x",-1310);

	set("coor/y",175);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
