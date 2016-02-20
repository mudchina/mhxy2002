// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "村中小路");
        set("long", @LONG
这是一条粹石铺成的小路，走到这里，抬眼望去，青山绿水，
四周都是朴素的村民和民居，往左走不远就是绿水湖了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"croad1",
  "east" : __DIR__"cunkou",
  "south" : __DIR__"chouse",
  "north" : __DIR__"chouse1",
]));
        set("objects", ([
        __DIR__"npc/xiaotong": 2,
        __DIR__"npc/farmer": 1,
                        ]) );
        set("coor/x",-1025);

	set("coor/y",15);

	set("coor/z",0);
	setup();
    }
