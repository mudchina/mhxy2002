inherit ROOM;

void create()
{
        set("short", "清波小轩");
        set("long", @LONG  
流光溢彩，清波淡云。这里是西海龙宫公主幽雾的香闺。
幽雾是敖顺最疼爱的女儿，在四海龙宫中也是数一数二
的美女。幽雾兰心慧质，这里四处都是她所刺绣的壁画。 
幅幅栩栩如生，龙凤狮虎，直欲破画而出。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
                "south" : __DIR__"zoulang6",
        ]));
        set("objects", ([
                __DIR__"npc/gongzhu":1,
        ]));
        setup();
}

