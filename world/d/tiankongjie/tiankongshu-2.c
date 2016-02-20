// Room: /d/tiankongjie/tiankongshu-2.c

inherit ROOM;

void create()
{
        set("short", "天空树第二层");
        set("long", @LONG
这里是天王的出生地。天王作为天界的王子他的仁爱，广为众神所知。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-1",
  "down" : __DIR__"tiankongshu-3",
]));

        setup();
        replace_program(ROOM);
}

