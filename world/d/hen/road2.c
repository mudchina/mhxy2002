// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡窝走道");
  set ("long", @LONG

        你走在鸡窝的走道上，到处都是鸡叫的声音，东面是小鸡
   休息的地方。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"rest",
          "north": __DIR__"road1",
         "south": __DIR__"road3",
]));

        setup();
}
