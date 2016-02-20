//by tianlin 2001.7.30

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", YEL"郊外小路"NOR);
  set ("long", @LONG

开封城是一个十分安静的地方,在这里能听到许多动物的叫声，
现在安静极了，只有一些小鸟喧杂的声音。

LONG);

  set("exits", ([
        "west" : __DIR__"xiaolu2",
        "south" : __DIR__"neishi",
      ]));

  setup();
}


