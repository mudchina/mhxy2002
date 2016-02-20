// kuangshan 矿山
// 星星lywin 2000/8/27 

#include <ansi.h>
inherit ROOM;

 void create()
{
        set("short", "矿山");
        set("long", @LONG
这儿是一座荒无人烟的矿山！山间和地面上能看到好多好多的矿脉，
矿藏极为丰富！据说这儿可以挖出几乎天下间所有制造护具用的好矿石。
我想你应该用来试试！
LONG
        );

        set("exits", ([
                "southdown" : "/d/kaifeng/east4",
                "east" : __DIR__"kuangshan2",
        ]));
	set("objects", ([
		__DIR__"kuang/kuangmai" : 3,
	//	"d/city/npc/xunbucao" : 2,
	])); 
        set("no_fight",1);
        set("no_beg",1);
        set("no_steal",1);
        setup();
	replace_program(ROOM);
}
