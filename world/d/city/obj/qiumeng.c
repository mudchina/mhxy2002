//by  xiaoran

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HIY"秋梦楼"NOR);
  set ("long", @LONG
临窗的地上铺著猩红毛毯，楼阁正面设著大红金钱蟒靠背，
石青金钱蟒引枕，秋香色金钱蟒大条褥。两边设一对梅花式
红漆小几，几上茗琬瓶花俱备，还有一个翡翠所造的箱子。
LONG);

  set("exits", ([
       "down" : __DIR__"caotang",
      ]));
  set("objects", ([
        "/d/city/npc/xianzi.c" : 1,
      ]));
  setup();
}
