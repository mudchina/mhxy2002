inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIC"灵界睡房"NOR);
        set("long", @LONG

灵界的一间睡房，房间干干净净，一排大床，供灵界弟子休息睡觉。
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

        set("exits", ([
                "out" : __DIR__"shengdian2",
        ]));

        setup();
}
