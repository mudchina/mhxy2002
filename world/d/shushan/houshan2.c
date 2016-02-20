//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","小路");
  set ("long", @LONG

这就是蜀山派的金鞭崖，远远望去黑云笼罩。你在想
是不是传说中的镇妖塔就在那里。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 1 */
      "southdown" : __DIR__"houshan1",
               "up" :  __DIR__"houshan3",
    ]));

  setup();
}






