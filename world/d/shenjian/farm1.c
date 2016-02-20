// LLY@FYSY
inherit ROOM;

void create()
{
	set("short", "菜地地");
	set("long", @LONG
一片绿油油的菜地。几个农夫正快乐的耕种着。 
LONG
	);
	set("exits", ([
		"south" : __DIR__"croad2",
		]));
	set("objects", ([
		__DIR__"npc/farmer" : 1,
	]));
	set("outdoors", "shenjian");
	set("coor/x",-1045);

	set("coor/y",20);

	set("coor/z",0);
	setup();
replace_program(ROOM);

}
