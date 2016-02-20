// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "小村口");
        set("long", @LONG
这是个小小的村落，村子里的人大多都姓谢。在这里你可以遥遥的望见不远
处波光摇曳的绿水湖,往旁边可以看到一座翠绿的山峰,大概就是江湖中人常常提
到的翠云峰了，要去神剑山庄的人,都要经过这里。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"croad", 
  "north" : __DIR__"cyf",
  "southeast" : __DIR__"road",
  "south" : __DIR__"yaodian",
]));

        set("outdoors", "shenjian");
        set("coor/x",-1015);

	set("coor/y",15);

	set("coor/z",0);
	setup();
}
