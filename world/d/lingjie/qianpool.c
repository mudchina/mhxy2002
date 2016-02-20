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
	add_action("do_swim", "swim");
}


int do_swim(string arg)
{
 object me=this_player();
 
    if (me->is_busy()) return notify_fail("你现在正忙着呢。");
  
	  if ((int)me->query_skill("force", 1)<180 )
	  {
	  message_vision("$N看了一眼湍急的水流，却不敢异动．\n", me);
   }
      else
        {
	  message_vision("$N看了看湍急的水流，奋身游了过去!。\n", me);
	  tell_object(me,"刚上岸，却发现一个少年以笑眯眯的冲着你!\n");
	  
   me->move(__DIR__"master.c");
        }
    me->receive_damage("kee", (int)me->query("max_kee")*10/100);
  return 1;
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



