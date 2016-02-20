// created 17-06-2001 海上飘(piao)

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "石巷尽头");
  set ("long", @LONG
石巷的尽头是一堵高墙，墙上有一道窄门。墙角有一狗洞
，一条脏稀稀的小河沟从狗洞中流出。时而不时的，一条条浸
满血水的绷带从狗洞中流出。
LONG
           );

  set("objects", ([ /* sizeof() == 1 */

__DIR__"obj/blood.c" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"baiyun",
  "north" : __DIR__"sroom",

]));

  create_door("north", "窄门", "south", DOOR_CLOSED);
set("valid_startroom", 1);
setup();
}

