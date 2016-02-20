// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "后院");
        set("long", @LONG
穿过树林来到这里，竟发现神剑山庄还有这么个地方，一个小小的
院子，种着一些不知名的花草，旁边还有个不高的小楼，不由的让人想
上楼去看看。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ty",
  "northup" : __DIR__"hyxl",
]));
        set("coor/x",-1310);

	set("coor/y",400);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
