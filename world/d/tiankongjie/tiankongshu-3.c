// Room: /d/tiankongjie/tiankongshu-3.c

inherit ROOM;

void create()
{
        set("short", "天空树第三层");
        set("long", @LONG
天界乐师闼婆王的出生地。四周飘散着美妙的音乐声，似乎闼婆王族的人都很喜
好音乐。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-2",
  "down" : __DIR__"tiankongshu-4",
]));

        setup();
        replace_program(ROOM);
}

