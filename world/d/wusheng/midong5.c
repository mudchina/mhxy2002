// changan wusheng
// midong5.c

inherit ROOM;

void create ()
{
  set ("short", "武圣密洞");
  set ("long", @LONG

这里光线极为微弱，你勉强地看见洞里隐隐约约的一些东西，
却又看得不是十分清楚。你不禁伸出手来扶着洞壁，小心地摸
索着行动。为什么在武圣门会有如此密洞，难道里面有宝物？

LONG);

  set("exits", ([
        "down" : __DIR__"room7",
      ]));
  set ("sleep_room",1);

  setup();
}



