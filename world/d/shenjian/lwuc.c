// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "武场");
        set("long", @LONG
几个放置兵器的架子摆放在墙边，上面放的全是各种各样的剑，神剑
山庄因剑得名，因剑闻名，所以庄中弟子练的也都是剑法。现在正有几名
弟子专心地练着剑法。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"wuc",
  "west" : __DIR__"nvs",
  "north" : __DIR__"lqhuayuan",
  "south" : __DIR__"ml",
]));
     set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard2" : 3,
	]));
  set("outdoors", __DIR__);
        set("coor/x",-1320);

	set("coor/y",240);

	set("coor/z",10);
	setup();
}
