// wdroad4.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "青石大道");
	set("long", @LONG
你走在一条青石大道上，四周静悄悄的。西边是一条大道，东边是好
大的一片树林。往南还有一条大道，掩映在密密的树林中。
LONG );
        set("outdoors", "wudang");
	set("exits", ([
		"west"    : __DIR__"wdroad5",
		"southeast"   : "/d/city/ximen",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

