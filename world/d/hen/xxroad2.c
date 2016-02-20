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
         "east": __DIR__"xxroad3",
         "west": __DIR__"xxroad1",
          "north": __DIR__"shenxue",
         "south": __DIR__"junshi",
]));

        setup();
}
