// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "渔溏");
	set("long", @LONG
这里是靠海的一个渔村,这里已水货出名,全村上下几百人全靠
打渔为生.这里附近有几个村民搞的小渔溏....
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "west" : __DIR__"daotian1",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
	set("objects", ([
		__DIR__"yu/yutan" : 2,
	])); 


	setup();
	replace_program(ROOM);
}
