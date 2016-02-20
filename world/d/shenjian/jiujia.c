// LLY@FYSY
#include <room.h>
inherit ROOM;
int do_north(string arg);
void create()
{
        set("short", "小小杏花村");
        set("long", @LONG
就像大多数别的地方一样，这酒家的名字也叫做杏花村。
要到神剑山庄去的人，通常都得经过这里的谢掌柜的转达。
酒家背湖而建，透过后面的竹门可以看到一个小小的船坞。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "south" : __DIR__"ctree",
]));
        set("objects", ([
        __DIR__"npc/waiter": 1 ,
        ]) );
        set("NONPC",1);
        set("coor/x",-1075);

	set("coor/y",15);

	set("coor/z",0);
set("no_magic",1);
	setup();
  }
void init()
{

add_action("do_north","north");
}
int do_north(string arg)
{
        object room;
        object me;
                me = this_player();
		if( (int)me->query_skill("sword",1) > 10 )
		 {
          message_vision("$N打开竹门，往屋后的小船坞走了过去,店小二在$N身后说道：你叫一声谢掌柜，自然会有人来接你。\n", me);
          room = load_object(__DIR__"jiujia2");
	      me->move(room);
//		 return notify_fail("");
		 return 1;
		 }
		 else
		 {
          message_vision("竹门后面一个飘渺的声音对$N说到：你对剑术的造诣还不够，还是快离开神剑山庄吧！                        \n", me);		  
		  return 1;
		 }
        }
	       

