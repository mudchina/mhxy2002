// LLY@FYSY
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "小屋");
        set("long", @LONG
大厅里四处都是明亮的，这间屋子里却是昏黄黯淡的一
副景象。屋子里的一个大木牌，一个木架，都蒙着块黑市，
显得更阴森冷寂。木架後还有件用黑布蒙着的东西，一件长
长的方方的东西。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"rpt",
]));
set("objects",([
  __DIR__"npc/master1" : 1,
  __DIR__"obj/coffin" : 1,
  __DIR__"obj/tablet" : 1,
  __DIR__"obj/shelf" : 1,
       	]) );
	setup();
}
