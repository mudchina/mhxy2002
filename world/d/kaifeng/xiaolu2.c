//by tianlin 2001.7.30

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HBBLU+CYN"郊外小路"NOR);
  set ("long", @LONG

开封城是一个十分安静的地方,在这里能听到许多动物的叫声，
前面就能看见一个类似小镇的地方,远远的能看清哪里有几个人,
好像再说些什么。

LONG);

  set("exits", ([
        "north" : __DIR__"xiaozhen",
        "east" : __DIR__"xiaolu",
      ]));

  setup();
}


