// link
inherit ROOM;
#include <room.h>
#include <ansi.h>
void create()
{
        set("short", HIC"回魂湖"NOR);
        set("long", @LONG
这里是回魂湖的中央，河流虽然不是很深，但脏得有些恶心。水面波涛
起伏与日光辉映，发出鱼鳞般的光芒。一个个的影子拍击的浪花，圈圈
水波打破了宁静和谐的溪面。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"qianpool",
  "south" : __DIR__"swimrm",
]));
      set("coor/x",40);
	set("coor/y",100);
	set("coor/z",-10);
        set("objects", ([
           __DIR__"obj/xueguo" : 1,
        ]) );
	setup();
	create_door("south", "水闸", "north", DOOR_CLOSED);
	create_door("north", "水流", "south", DOOR_CLOSED);
}
void init()
{
	if(interactive(this_player()))
	call_out("do_flush",5,this_player());
}

void do_flush(object me)
{
	object room;

	if(!me || environment(me) != this_object())
                return;
	tell_object(me,"你奋力向前游去……\n");
	room= load_object(__DIR__"qianpool");
	me->move(room);
	me->add("gin",-40);
	me->add("kee",-40);
}	
