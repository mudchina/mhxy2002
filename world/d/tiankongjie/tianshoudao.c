// Room: /d/tiankongjie/tianshoudao.c

inherit ROOM;

void create()
{
        set("short", "天手岛");
        set("long", @LONG
这里是踏入天空界的跳板。这里是一片绿色的草的海洋。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"pingchengmen.c",
  "enter" : __DIR__"yueguangku.c",
]));

        setup();
        replace_program(ROOM);
}

