// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "村中小路");
        set("long", @LONG
这是一条粹石铺成的小路，下方有一家客栈可以休息休息，
走到这里，抬眼望去，青山绿水，四周都是朴素的村民和民居
，绿水湖越来越近了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"croad",
  "west" : __DIR__"croad2",
  "south" : __DIR__"chotel",
  "north" : __DIR__"chouse2",
]));
        set("objects", ([
        __DIR__"npc/farmer": 1,
                        ]) );
       set("coor/x",-1035);

	set("coor/y",15);

	set("coor/z",0);
	setup();
       }
