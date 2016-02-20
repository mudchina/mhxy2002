// LLY@FYSY
inherit ROOM;

void create()
{
	set("short", "庄稼地");
	set("long", @LONG
一片茫茫无边的稻田。田中稻草随风而动，几个农夫正快乐
的耕种着。 
LONG
	);
	set("exits", ([
		"north" : __DIR__"croad2",
		]));
	set("objects", ([
		__DIR__"npc/farmer" : 1,
	]));
	set("outdoors", "shenjian");
	set("coor/x",-1045);

	set("coor/y",10);

	set("coor/z",0);
	setup();
replace_program(ROOM);

}
