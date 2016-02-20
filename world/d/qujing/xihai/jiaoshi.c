//edit by lucas

inherit ROOM;

void create ()
{
  set ("short", "礁石缝");
  set ("long", @LONG
这里是礁石的缝隙，几块大珊瑚礁犹如几扇巨大的屏风一样
遮挡住外面的海流，只留给里面无限的安静和黑暗。一个小
妖怪坐在地上的一块岩石上，正翘着二郎腿休息。
LONG);

  set("water", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"haidi4",
]));
        set("objects", ([
       "/d/qujing/heishui/npc/xiaoyao":1,
        ]));
        set("no_magic",1);
        setup();
}

