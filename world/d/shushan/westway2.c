//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","西小路");
	set ("long", @LONG

这是天师洞西厢的一条小路, 小路是由青石铺成地，打扫的
极为干净，走在上面感到非常平坦。小路的西面是斋房，
不时的飘出一阵饭香。
LONG);

	set("exits", ([     
       "north" : __DIR__"westway3",
       "south" : __DIR__"westway1",
        "west" : __DIR__"zhaifang",
       ]));

	setup();
}
