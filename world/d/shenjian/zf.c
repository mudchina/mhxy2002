// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "帐房");
        set("long", @LONG
整间屋子都是由坚硬的花岗石砌成的，屋中摆着一个小桌，桌上
摆满了帐本，这里就是神剑山庄的帐房了，神剑山庄人丁众多，开支
也就不小，所有的开支都要经过这里。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rroad",
 ]));
set("objects", ([
		__DIR__"npc/xiansheng" : 1,
                __DIR__"npc/guard3" : 2,
                  __DIR__"npc/guard" : 1,
	]));
	setup();
}
