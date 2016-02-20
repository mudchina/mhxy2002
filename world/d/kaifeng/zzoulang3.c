// by cih 10/01/2002
// Room: /d/kaifeng/zzoulang

inherit ROOM;

void create ()
{
  set ("short","空中走廊");
  set ("long", @LONG

这里是这条名冠开封的走廊的尽头了。虽然走廊没有了，看是从这
里可以看到北边的花园里花香鸟语，非常的美丽，热闹。不知道是
怎么会事，那个花园一年四季都是这个样子。也不晓得是不是天蓬
元帅动了什么手脚。。。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"zketing",
  "south" : __DIR__"zzoulang2",
]));
  set("outdoors","kaifeng");
  setup();
}
