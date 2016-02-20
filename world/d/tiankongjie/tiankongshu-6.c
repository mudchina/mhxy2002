// Room: /d/tiankongjie/tiankongshu-6.c

inherit ROOM;

void create()
{
        set("short", "天空树第六层");
        set("long", @LONG
天空界的居民居住的地方。这人声鼎沸，一片繁荣的景象。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-5",
  "down" : __DIR__"tiankongshu-7",
]));

        setup();
        replace_program(ROOM);
}

