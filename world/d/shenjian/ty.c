// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "庭院");
        set("long", @LONG
走出大厅，就来到了一个庭院，四周种着一大片的古树
，抬眼望去，只见几缕阳光射在落叶铺成的路面上，四周都
是黑森森的,还是不要乱走了。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"hy",
  "south" : __DIR__"dt",
  "east" : __DIR__"tt6",
  "west" : __DIR__"tt2",
]));
	setup();
}
