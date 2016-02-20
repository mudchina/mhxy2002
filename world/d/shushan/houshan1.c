//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","后山路");
  set ("long", @LONG

这里是通往蜀山派后山的山路，这里道路平坦,看来是常有人来。
旁边是看不见底的悬崖，你小心翼翼的走着。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 1 */
      "southwest" : __DIR__"houshan0",
        "northup" : __DIR__"houshan2",

 ]));

  setup();
}






