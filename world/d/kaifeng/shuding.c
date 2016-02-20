//by tianlin 2001.7.30

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIG"墙外"NOR);
  set ("long", @LONG

这里是开封的墙外,这里不经常有人来,突然你发现
一个很奇怪的人站在那里,长的还挺象猪八戒的.
LONG);

  set("exits", ([
        "翻墙" : __DIR__"zhu2",
      ]));
  set("objects", ([
        __DIR__"npc/zhuxiaojie" :  1,
        __DIR__"obj/jingangpa" :  1,
      ]));

  setup();
}

