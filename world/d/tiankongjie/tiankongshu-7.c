
// Room: /d/tiankongjie/tiankongshu-7.c

inherit ROOM;

void create()
{
        set("short", "天空树第七层");
        set("long", @LONG
那罗王的出生地。龙王是在北面的龙之海高原出生的, 而比婆王则是在南面的热情原野出生的。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-6",
  "down" : __DIR__"pingchengmen.c",
]));

        setup();
        replace_program(ROOM);
}

