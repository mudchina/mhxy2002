// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡窝走道");
  set ("long", @LONG

        你走在鸡窝的走道上，到处都是鸡叫的声音，东面传来了一阵朗朗的
    读书声，西面好象是个商业街。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad1",
         "west": __DIR__"syroad1",
          "north": __DIR__"road3",
         "south": __DIR__"road5",
]));

        setup();
}
