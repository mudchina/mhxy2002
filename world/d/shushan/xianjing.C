inherit ROOM;
void create ()
{
  set ("short", "仙境");
  set ("long", @LONG

模模糊糊中，你来到一个陌生的地方。这里四面都是云彩，但你看不到天
空。脚下都是雾，但你看不到地面。也不知这里是真，是幻。
LONG);
  set("objects", ([ 
      __DIR__"npc/jianshen" : 1,
  ]));
  set("light_up", 1);
  setup();
}
