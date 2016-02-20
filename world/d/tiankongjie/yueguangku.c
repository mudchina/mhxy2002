// Room: /d/tiankongjie/yueguangku.c

inherit ROOM;

void create()
{
        set("short", "月光窟");
        set("long", @LONG
这里是进入天空界的唯一通道。兰色的光芒从洞的深处幽幽荡出来。周围
长满了，各种奇珍异草。使你感觉到一种来到世外桃源的感觉，你将要大
步迈出但是有被这里的环境所迷住。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bianjing.c",
  "out" : __DIR__"tianshoudao.c",
]));

        setup();
        replace_program(ROOM);
}

