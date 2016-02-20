// Room: /d/tiankongjie/tiankongshu-5.c

inherit ROOM;

void create()
{
        set("short", "天空树第五层");
        set("long", @LONG
迦楼罗王的出生地。天空中飞舞着各种各样的鸟类。凤凰宫的光芒耀眼夺目。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-4",
  "down" : __DIR__"tiankongshu-6",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/lijia" : 1,
]));

        setup();
        replace_program(ROOM);
}

