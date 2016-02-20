//link
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", HIC"回魂湖"NOR);
        set("long", @LONG
这里是灵界的回魂湖。也许是来这里的人比较少的缘故吧，这里的
湖水保养得很干净，碧绿的湖水波光粼粼，倒是挺可爱的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"shengdian",
  "north" : __DIR__"pool",
]));
	set("valid_startroom",1);
        set("objects", ([
	__DIR__"obj/pool" : 1,
                        ]) );
        set("coor/x",40);
	set("coor/y",80);
	set("coor/z",0);
	setup();
	create_door("north", "水闸", "south", DOOR_CLOSED);
}
void init()
{		
	add_action("do_swim","swim");
}

int do_swim()
{
	object me;
	object room;
	me = this_player();
	message_vision("$N跳进水中，开始游泳．．．\n",me);
	room = load_object(__DIR__"pool");
	me->move(room);
	me->add("gin",-40);
	me->add("kee",-40);
	return 1;	
}
