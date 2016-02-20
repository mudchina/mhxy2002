// Room: /d/tiankongjie/bianjing.c

inherit ROOM;

void create()
{
        set("short", "边境");
        set("long", @LONG
这里就是天空界的边境了。环境似乎已经不一样了。一条直路向上，两旁是无边
云海！！！云海中还竖立着一条彩虹，彩虹的周围还有几只仙鹤在飞翔，显得这里更
是秒美绝伦。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yueguangku.c",
]));

set("valid_startroom", 1);
        set("outdoors", "tiankongjie");
        setup();
        replace_program(ROOM);
}

