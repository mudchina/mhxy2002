// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡窝走道");
  set ("long", @LONG

        你走在鸡窝的走道上，到处都是鸡叫的生意，东面是喂小鸡
   的地方，西面是给小鸡洗澡的地方。

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
         "north" : __DIR__"room",
         "east": __DIR__"feed",
         "west": __DIR__"bathe",
         "south": __DIR__"road2",
]));

        setup();
}
