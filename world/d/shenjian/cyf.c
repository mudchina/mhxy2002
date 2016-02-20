// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "翠云峰下");
        set("long", @LONG
两旁是茂密的树林，前面是一条崎岖的山路，顺着山路看去，满目青翠，
一阵阵山风带着绿草和泥土的芬芳扑面而来。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"cyf1",
  "south" : __DIR__"cunkou",
]));
        set("coor/x",-1015);

	set("coor/y",25);

	set("coor/z",0);
set("no_magic",1);
	setup();
}
