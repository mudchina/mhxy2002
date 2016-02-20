inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "天机堂");
  set ("long", @LONG

一进天机堂，你就看见形形色色的人进进出出，一个高大中年男子
正忙着批改文书，处理大小事物。
LONG);

  set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/long" : 1,
  __DIR__"npc/shinv" : 2,
]));
  set("exits", ([ /* sizeof() == 1 */
   "west" : __DIR__"dating4",
]));
set("no_time",1);
set("no_fight",1);
set("no_magic",1);
  setup();
}
