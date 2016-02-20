// changan wusheng
// shijie6.c

inherit ROOM;

void create()
{
  set ("short", "石阶");
  set ("long", @LONG

走入这里，风景仿如仙境，与山前的石路简直是两个截然不同的
感觉。
LONG);
set("exits", ([ /* sizeof() == 4 */
"northup": __DIR__"shijie7",
"southdown": __DIR__"shijie5",
]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

