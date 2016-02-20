//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG
水波流动，条条海带在水中随波逐流，珊瑚丛中也时而荡起一条被
水流冲出的海马，海龟笨重地挪动着它那庞大的身躯，金枪鱼在石
缝间寻觅着食物，无数海底生物在这休养生息，无拘无束地自在生
活。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"haidi3",
  "west" : __DIR__"haidi5",
  "south" : __DIR__"jiaoshi",
]));
        setup();
}

