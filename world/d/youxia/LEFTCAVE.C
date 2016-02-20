inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "左边小洞");
        set("long", @LONG
钻进洞中抬头望去，黑暗中依稀看到山洞顶部凹凸不平，上面
有许多草藤交织成的巢穴，也不知是如何固定在上面的，刚好有一
只小鸟从穴中飞出，沿洞壁盘旋一周，鸣叫着又钻了回去。到处都
是寒冰！
LONG
        );
	set("frozen",10);
        set("item_desc", ([
                "寒冰": "
一块似乎是千年寒冰的东西挡住了你了去路。\n",
        ]) );

set("exits", ([ /* sizeof() == 4 */
	"out" : __DIR__"waterfall",
	]));

        set("objects", ([
                __DIR__"obj/icy_boot" :1,
                __DIR__"obj/icy_cloth" :1,
                __DIR__"obj/icy_girth" :1,
                __DIR__"obj/icy_ribbon" :1,
                        ]) );
        set("coor/x",230);
	set("coor/y",-280);
	set("coor/z",40);
	setup();
}

