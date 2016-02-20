inherit ROOM;

void create()
{
        set("short", "练功室");
        set("long", @LONG  
这里是西海豪杰练功的地方。此处四处摆满了刀枪剑戢，
有三个练功用的鱼人正在盯着你打量，不知打什么主意。
他们武艺精湛，是奉敖顺之命来此陪练的。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"yanwu",
        ]));
        set("objects", ([
                __DIR__"npc/yuren":3,
        ]));
        setup();
}

