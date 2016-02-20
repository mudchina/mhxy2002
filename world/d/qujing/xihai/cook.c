//edit by lucas
inherit ROOM;

void create ()
{
  set ("short", "御膳房");
  set ("long", @LONG 
这里是西海龙宫的御膳房，阵阵香气飘来，谗得你口水直流，
人言“靠山吃山，靠水吃水”，难得来一次龙宫，怎能不好
好享受一番海味呢？
LONG);

  set("exits", ([
        "east"   : __DIR__"zoulang5",
      ]));
  set("objects", ([
        __DIR__"obj/fish" : 1,
        __DIR__"obj/xierou" : 1, 
        __DIR__"obj/xiaren" : 1,
        __DIR__"obj/baoyu" : 1,
      ]));

  setup();
}

