inherit ROOM;
void create ()
{
  set ("short", "岩石路");
  set ("long", @LONG

走在这条路上你隐隐约约的感觉到一阵阵的热浪扑面而来
硫黄的刺鼻的味道也是愈来愈浓。
LONG);

  set("exits", ([
        "west" : __DIR__"road2",
        "southeast" : __DIR__"road4",
      ]));
  set("outdoors", "mojiao");
  setup();
}
