//By tianlin@mhxy for 2001.9.27
//部分优化

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，北面是三清殿，南面是一个圆形的门洞，有一条小路通往
后山。
LONG );
        set("exits", ([
                "south" : __DIR__"xiaolu1",
                "north" : __DIR__"sanqingdian",
        ]));
        set("objects", ([
                __DIR__"npc/yu" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
