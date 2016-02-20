// link

inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", BLU"回魂湖深处"NOR);
        set("long", @LONG
这里的湖水应该说是很深的了，只有轻功水平很高的人才敢来这里
游，你可要小心一点，别被水充走。
......水流越来越急，几乎已经立不住足了......
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"pool",
]));
      	set("coor/x",40);
	set("coor/y",120);
	set("coor/z",-20);
	setup();
	create_door("south", "水流", "north", DOOR_CLOSED);
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",10,this_player());
}

void do_flush(object me)
{
        object room;
	if(!me || environment(me) != this_object())
		return;
	tell_object(me,"一阵暗流涌来，你被巨大的水流一冲，就什么也不知道了……\n");
	room= load_object("/d/lingjie/lang");
	me->move(room);
}	
