// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "居室");
        set("long", @LONG
这里是庄中侍卫庄丁们寝息起居的地方，四处摆放着一些盔甲和剑具。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rwuc",
]));
set("objects", ([
		__DIR__"npc/guard3" : 1,
                __DIR__"npc/guard" : 2,
	]));
        set("coor/x",-1290);

	set("coor/y",240);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
