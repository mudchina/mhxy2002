// 灵月小路 by Calvin

inherit ROOM;

void create()
{
  set ("short", "灵月小路");
set("long", @LONG

         一条通往灵月仙界的小路。

LONG );

set("exits", ([
  "southwest"   : "/d/southern/wutai/guandao3",
  "east"   : __DIR__"lu1",
]));

set("objects", ([
]));

set("outdoors", 1);
setup();
}
