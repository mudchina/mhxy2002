// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "上山路");
        set("long", @LONG
山林夹道，走到这里，只剩一条弯曲的小路勉强可以行走了。站
在这里，可以看到谢家村就在脚下，不远的低处，湖水拍岸的声
音不停的传过来。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"cyf1",
  "northup" : __DIR__"cyf2",
]));
       set("coor/x",-1025);

	set("coor/y",45);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
