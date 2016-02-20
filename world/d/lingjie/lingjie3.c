#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "灵界");
  set ("long", @LONG

四周一片黑暗,到了这里,便于外界失去了任何联系,你只有在
这无边无际的黑暗中到处摸索,不停前进了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"lingjie2",
  "north" :  __DIR__"lingjie5",
  "south" : __DIR__ "lingjie4",
  "west" : __DIR__ "lingjie6",
  "east" : __DIR__ "lingjie7",
]));

  setup();
}



