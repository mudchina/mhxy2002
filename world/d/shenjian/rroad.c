//By tianlin@mhxy for 2002.1.10
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山庄前院");
        set("long", @LONG
一进庄来，你的视野豁然开朗，刚才的压抑一扫而光。此处建筑琉
璃生光，脚下是一条花岗岩铺制的道路，左右皆是芳草荫荫，无数的白
鸽歇息四处，见得有人过来，边望一旁飞去。左边不远处传来马嘶的声
音，想必是马廊了，右边是一个帐房，不时有人进出。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wuc",
  "south" : __DIR__"sjsz",
  "east" : __DIR__"zf",
  "west" : __DIR__"ml",
]));
set("objects", ([
		__DIR__"npc/guard3" : 2,
                __DIR__"npc/guard" : 1,
          	]));
  set("outdoors", __DIR__);
             set("coor/x",-1310);

	set("coor/y",230);

	set("coor/z",10);
	setup();
}
