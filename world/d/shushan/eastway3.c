//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","东小路");
	set ("long", @LONG

这是天师洞东厢的一条小路, 小路是由青石铺成地，打扫的
极为干净，走在上面感到非常平坦。小路两面的有一些奇形
怪状的石雕。东面是练功房，你看到有很多人在那里练功。
LONG);

	set("exits", ([     
       "north" : __DIR__"eastway4",
       "south" : __DIR__"eastway2",
        "east" : __DIR__"liangongfang",
       ]));
        setup();
}
