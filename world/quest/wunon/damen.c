// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
        set("short", "农庄大门");
        set("long", @LONG
这里是农庄大门,进了这个门里面就是农庄了,是专门生产
各种食物的地方,如果你想学习务家术,那么你就找对地方了.
LONG
        );
        set("no_clean_up", 0);
        set("outdoors", "jiangnan");
        set("exits", ([
                "north" : "d/gao/road3",
                "south" : __DIR__"daotian1",
        ]));

        set("objects", ([
//                "d/city/npc/xunbucao" : 2,
        ])); 
        setup();
        replace_program(ROOM);
}