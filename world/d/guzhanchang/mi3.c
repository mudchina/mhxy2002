// Room: /shulin/lin3.c
inherit ROOM;
void create()
{
        set("short", "迷阵");
        set("long", @LONG
这里就是古战场的遗址了，听说这里有怪物出没，你还不快走，难道想被怪物吃掉么。
LONG );
        set("exits", ([
                "west" : __FILE__,
                "east" : __DIR__"mi2",
                "south" : __FILE__,
                "north" : __FILE__,
                "northeast" : __DIR__"mi4",
                "southeast" : __FILE__,
        ]));
         set("objects", ([
             __DIR__"npc/jiangshi" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

