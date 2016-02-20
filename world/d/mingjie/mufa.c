// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "鬼筏");
  set ("long", @LONG

到处都是黑色，黑色的天，黑色的水，一个黑色的世界...
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"wu.c",
]));
set("zuo_trigger", 0);
  set("outdoors", 1);

  setup();
}
