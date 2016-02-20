// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "打猎场");
	set("long", @LONG
这里是一大块的草原,上面野味成群,风影独特...
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "east" : __DIR__"daotian1",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
	set("objects", ([
		__DIR__"dalie/dalie" : 2,
	])); 


	setup();
	replace_program(ROOM);
}
