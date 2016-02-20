inherit ROOM;
void create ()
{
  set ("short", "山石路");
  set ("long", @LONG

一下了石路，一股浓烈的热风吹的你东倒西歪，两边是悬崖绝壁
悬崖下则是翻腾乱涌的岩浆，你不禁打了个寒噤。
LONG);

  set("exits", ([
        "northwest" : __DIR__"road3",
        "southeast" : __DIR__"road5",
      ]));
  set("outdoors", "mojiao");
  setup();
}
