// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "村外小道");
        set("long", @LONG
这是一条粹石铺成的小道，走到这里，抬眼望去，一座山峰
就在头顶，往前走不远就是闻名天下的绿水湖了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cunkou",
  "north" : __DIR__"shop",
  "south" : "/d/city/dongmen",
  ]));
        set("objects", ([
        __DIR__"npc/xiaotong": 1,
        __DIR__"npc/jifu": 1,
                            ]) );
        set("coor/x",-1010);

	set("coor/y",10);

	set("coor/z",0);
	setup();
    }
