//water.c
//edit bye lucas
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "水幕");
        set("long",@LONG
这里是一大片水幕之中。此水幕由西海万水所成，笼罩的滴水不漏，
外面是西海万里波顷之下，只见水族种种，时而翩翩游弋，时而跃
扑蓝天，摩昂与一大群虾兵蟹将正推波助澜，神速前进。
LONG );
        set("no_clean_up", 0);
        set("exits", ([
        ]));
        set("objects", ([
             __DIR__"npc/xiabing" : 2,
             __DIR__"npc/xiejiang" : 2,
        ]));

        setup();
}

