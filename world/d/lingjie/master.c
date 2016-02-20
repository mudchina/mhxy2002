
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"回魂湖边"NOR);
        set("long", @LONG
深黑湖水里似乎有无数的幽灵在颤动，少年站在那里右手平伸，手握成
枪状，左手扶在右手手腕处，好熟悉的动作-----灵丸！
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "out" : __DIR__"pool",
        ]));
        set("objects", ([
                 "/d/lingjie/npc/youzhu.c" : 1,
				         ]));

        setup();
}