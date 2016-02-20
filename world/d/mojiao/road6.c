inherit ROOM;
void create ()
{
  set ("short", "山石路");
  set ("long", @LONG

走下了山崖，你眼前一亮，热风也没了，四处花草茂盛
与先前的枯燥的景色偈然不同。
LONG);

  set("exits", ([
        "northwest" : __DIR__"road5",
        "east" : __DIR__"gate",
      ]));
  set("outdoors", "mojiao");
  setup();
}
