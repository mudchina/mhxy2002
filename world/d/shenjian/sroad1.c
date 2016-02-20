// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "枫林小路");
        set("long", @LONG
左右都是枫叶飘舞，远远望过去，神剑山庄那宏伟古老的建
筑，已隐约可见。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sroad2",
  "south" : __DIR__"sroad",
]));
          set("coor/x",-1310);

	set("coor/y",185);

	set("coor/z",10);
set("no_magic",1);
	setup();
}
