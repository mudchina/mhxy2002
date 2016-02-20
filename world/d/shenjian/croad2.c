// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "村中小路");
        set("long", @LONG
路已经到了尽头，前面是湖畔的一块空地，抬眼便是绿水湖了，清澈
的湖水中倒影着翠绿的山影，到了这里，你不由的想起武林中常说的：翠
云峰，绿水湖，神剑山庄。心中油然生出一种朝圣的感觉。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"croad1",
  "west" : __DIR__"sjhupan",
   "south" : __DIR__"farm",
  "north" : __DIR__"farm1",
]));
        set("objects", ([
        __DIR__"npc/xiaotong": 1,
        __DIR__"npc/farmer": 2,
                        ]) );
        set("coor/x",-1045);

	set("coor/y",15);

	set("coor/z",0);
	setup();

}
