// by happ@YSZZ
inherit ROOM;

void create ()
{
  set ("short", "鸡场入口");
  set ("long", @LONG

        这里是星空战斗鸡的诞生地，如果你也想养一只小鸡，就向
    小二买一只吧！

LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
  "out" : "/d/city/kezhan",
  "south" : __DIR__"road1",
  "west" :__DIR__"home",
]));


  set("objects", ([//sizeof() == 1
    __DIR__"npc/waiter" : 1,
  ]));
        setup();
}
