
// Room: /shulin/lin1.c
inherit ROOM;
void create()
{
        set("short", "路口");
        set("long", @LONG
这里就是古战场遗址的入口了，听说里边有怪物出没，没有一定工夫还是别去的好。
LONG );
        set("exits", ([
                "east" : __FILE__,
                "west" : __FILE__,
                "south" : __DIR__"mi2",
                "north" : __FILE__,
                "down"      : "/d/changan/nanyue",

        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

