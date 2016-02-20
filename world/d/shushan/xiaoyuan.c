//shushan by yushu 2000.11
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create ()
{
  set ("short",HIR "「"HIY "院内" HIR "」" NOR);
  set ("long", @LONG

这是蜀山派派的院内,青砖铺成的地显得格外干净
有几个蜀山派派弟子正在这里练武。
LONG);

  set("outdoors", "/u/dragon/kfadd/door");
  set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/shushan/dadian",
  "out" : __DIR__"door",
  ]));

create_door("out", "石门", "enter", DOOR_CLOSED);
  setup();
}
