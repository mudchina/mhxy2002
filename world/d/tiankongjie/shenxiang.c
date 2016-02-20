// Room: /d/tiankongjie/shenxiang.c

inherit ROOM;

void create()
{
        set("short", "神像殿");
        set("long", @LONG
天空殿的神像就耸立在这里。这里似乎是天空届的领导中枢。精神总领。
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huiming" : 1,
]));
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tiankongshu-1",
]));

        setup();
        replace_program(ROOM);
}

