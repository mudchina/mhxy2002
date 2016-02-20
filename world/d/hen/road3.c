// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡窝走道");
  set ("long", @LONG

        你走在鸡窝的走道上，到处都是鸡叫的声音，东面是卖小鸡食物
   的地方，西面是一家杂货铺。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"foodshop",
         "west": __DIR__"miscshop",
          "north": __DIR__"road2",
         "south": __DIR__"road4",
]));

        setup();
}
