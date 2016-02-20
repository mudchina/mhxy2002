// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "绿水湖畔");
        set("long", @LONG
眼前枫叶飞舞，站在这里，可以看到远处的山峰，晚风中充
满了乾燥木叶的清香，和一种从远山传来的芬芳。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"sroad",
]));
set("objects",([
			__DIR__"npc/xws" : 1,
       	]) );
         set("coor/x",-1310);

	set("coor/y",165);

	set("coor/z",0);
set("no_magic",1);
	setup();
}
