// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "山庄正院");
        set("long", @LONG
正院的前方通向庄主会客的白梅阁，左右两方则是山庄的左
右偏院。山风穿堂而过，四季都有的白烟笼罩着白梅阁。阁前白
玉石阶布满了各色的花瓣。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cleft",
  "east" : __DIR__"cright",
  "north" : __DIR__"guodao",
  "south" : __DIR__"road",
]));
        set("outdoors", "wanmei");

        set("coor/x",170);
	set("coor/y",-400);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
