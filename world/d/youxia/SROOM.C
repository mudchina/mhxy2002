// created 17-06-2001 海上飘(piao)


inherit ROOM;
#include <room.h>
void create()
{
	set("short", "堂屋");
	set("long", @LONG
屋子里潮湿而阴暗，屋子并不十分窄小，但只有一桌，一
床，一凳，更显得四壁箫然，空洞寂寞。也衬得那一盏孤灯更
昏黄暗淡。壁上的积尘未除，屋面上还结着蛛网。
LONG
               );
	 set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/yegucheng": 1, 
__DIR__"obj/blood": 1, 

]));
  set("exits", ([ /* sizeof() == 4 */
 "south" : __DIR__"stone2",


]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
]));

create_door("south", "窄门", "north", DOOR_CLOSED);
  setup();
}
