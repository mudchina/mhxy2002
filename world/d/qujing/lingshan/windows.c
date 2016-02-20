//live
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIC"灵山峰顶"NOR);
        set("long", @LONG
      这里就是灵山的禁区，常人是不敢来的
LONG
        );
        
        set("exits", ([ /* sizeof() == 2 */
                "enter" : __DIR__"houdian",
        ]));
        set("objects", ([
                 "/d/qujing/lingshan/npc/shenjiang.c" : 1,
			//	 "/d/qujing/lingshan/npc/tianbing.c" : 3,
        ]));

        setup();
}