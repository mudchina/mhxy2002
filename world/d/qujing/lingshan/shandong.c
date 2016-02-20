
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"灵山囚洞"NOR);
        set("long", @LONG
昏暗的灯光，一位老者坐在那里，千百年来如一日。
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "out" : __DIR__"houdian",
        ]));
        set("objects", ([
"/d/xueshan/npc/kongquedapeng.c" : 1,
				         ]));

        setup();
}
