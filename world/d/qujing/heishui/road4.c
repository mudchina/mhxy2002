inherit ROOM;

void create ()
{
  set ("short", "山道");
  set ("long", @LONG
这里是一片荒凉的山道，四周茅草丛生，灌木茂盛。到处静悄
悄的，听不到一点鸟兽的声音。远处传来哗啦啦的水响，看来
有一条大河吧。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road3",
  "southwest" : __DIR__"hean5",
]));

        set("outdoors", "heishui");

  setup();
}


