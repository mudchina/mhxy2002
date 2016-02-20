// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "龙泉酒店造酒房");
	set("long", @LONG
这是一间龙泉酒店造酒房！四周都是乱七八糟的造酒原料，人们
把在这用各种材料造酒。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "west" : __DIR__"shaocailie",
        ]));
	set("objects", ([
		__DIR__"jiu/zhaojiu" : 10,
	])); 


	setup();
	replace_program(ROOM);
}
