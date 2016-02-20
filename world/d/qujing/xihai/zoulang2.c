inherit ROOM;

void create()
{
        set("short", "走廊");
        set("long", @LONG
这里是龙宫走廊，雕栏画柱，盘龙飞凤，气派非凡。这里深
幽安静。一般龙子龙孙，虾公虾婆，决不敢在此喧哗吵闹。
天花板上以描金细缕，刻画着当年西海龙王平定西海的丰功
伟绩。 
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"dian",
                "east" : __DIR__"zoulang4",
                "north" : __DIR__"zoulang8",
        ]));

        setup();
}

