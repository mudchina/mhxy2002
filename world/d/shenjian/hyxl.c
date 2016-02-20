// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "后院小楼");
        set("long", @LONG
小栖上灯火凄凉，一上楼便可看到一个衰老而憔悴的妇人，默
默的坐在孤灯畔。彷佛在等待。她等的是什麽人？
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "southdown" : __DIR__"hy",
]));
set("objects",([
 __DIR__"npc/oldwoman" : 1,
 __DIR__"npc/master" : 1,
       	]) );
        set("coor/x",-1310);

	set("coor/y",410);

	set("coor/z",20);
	setup();
}
