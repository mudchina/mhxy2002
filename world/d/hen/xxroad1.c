// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "大学路");
  set ("long", @LONG

        这里全是学习的地方，有学文，也有学武的，不过这都不是
    义务教育，全部要收费的哦。

LONG);

  set("exits", ([ /* sizeof() == 4 */
         "east": __DIR__"xxroad2",
         "west": __DIR__"road4",
          "north": __DIR__"kexue",
         "south": __DIR__"poem",
]));

        setup();
}
