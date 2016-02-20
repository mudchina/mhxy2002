// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "湖畔树林");
        set("long", @LONG
一棵棵绿柳垂在湖畔，走了几步隐约可以看到一大片杏花树丛中
飘着一个锈着“小小杏花村”的酒旗。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"sjhupan",
  "north" : __DIR__"jiujia",
]));
        set("coor/x",-1065);

	set("coor/y",15);

	set("coor/z",0);
set("no_magic",1);
	setup();

}
