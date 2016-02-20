// Room: /d/sandboy/daotian2.c

inherit ROOM;

void create()
{
	set("short", "稻田");
	set("long", @LONG
金灿灿的一片稻田,微风轻送,谷浪涟涟,远望去,一片金色,直连到天的
尽头.稻草人手中摇晃着破扇子,守卫着今年的好收成.东面有一片晒谷场.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "north" : __DIR__"daotian1",
                "south" : __DIR__"daotian3",
                "west" : __DIR__"liechang2",
                "east" : __DIR__"yutian2",
        ]));
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
	set("objects", ([
		__DIR__"non/nontian" : 2,
	])); 

	setup();
	replace_program(ROOM);
}
