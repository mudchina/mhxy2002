//By tianlin@mhxy for 2001.12.30

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", HIY"→"HIC"〓"HIY"←"HIR"密室"HIY"→"HIC"〓"HIY"←"NOR);
  set ("long", @LONG

这里就是阴间冥王练功的密室了,这里堆瞒了乱七八糟的东西,
冥王正在那里盘腿打坐冥思。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"new-walk2",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/mingwang" : 1,
]));

  setup();
}
