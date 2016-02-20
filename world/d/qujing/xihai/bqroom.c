inherit ROOM;

void create()
{
        set("short", "兵器房");
        set("long", @LONG  
这里是兵器房，演武场上要举行赛事，都要到这先拿取
武器。西海龙宫风气尚武，所以这里的武器都是千挑万
选的精良兵器。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"yanwu",
        ]));
        set("objects", ([
                __DIR__"obj/rack":1,
                __DIR__"npc/xiabing":1,
                __DIR__"npc/xiejiang":1,
        ]));
        setup();
}

