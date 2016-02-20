// Room: /shulin/lin6.c
inherit ROOM;
void create()
{
        set("short", "迷阵");
        set("long", @LONG
这里就是古战场的遗址了，听说这里有怪物出没，你还不快走，难道想被怪物吃掉么。
LONG );
        set("exits", ([
                "east" : __DIR__"mi5",
                "west" : __FILE__,
                "south" : __FILE__,
                "north" : __FILE__,
                "southeast" : __DIR__"mi7",
                "northwest" : __FILE__,
        ]));
          set("objects", ([
             __DIR__"npc/kulou" : 1,
        ]));
 set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
 

