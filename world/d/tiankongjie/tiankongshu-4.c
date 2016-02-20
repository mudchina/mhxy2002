// Room: /d/tiankongjie/tiankongshu-4.c

inherit ROOM;

void create()
{
        set("short", "天空树第四层");
        set("long", @LONG
吉祥天的出生地, 也是光流之泉所在的地方。人到了这里似乎也感觉的心旷神怡。
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jixiangtian" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-3",
  "down" : __DIR__"tiankongshu-5",
]));

        setup();
        replace_program(ROOM);
}

