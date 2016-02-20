#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
     set("short",HIW"魔教入口"NOR);
     set("long",

"这里就是魔教的入口了，四面的熔岩到处飞腾，空气中散布着一股硫磺的味道\n"
"看来传说魔教第子善用火一点也不假。\n"
);
  set("exits", ([ /* sizeof() == 2 */
                "west":"/d/moon/kunlun",
                "east":"/d/mojiao/road1",
]));
 setup();
      replace_program(ROOM);
}
