// LLY@FYSY
#include <room.h>
inherit ROOM;
int do_north(string arg);
void create()
{
        set("short", "翠云峰顶");
        set("long", @LONG
爬上陡峭的山壁，左右云雾缭绕，抬眼望去，翠云峰顶竟是如此的
美丽，四处是芳芳绿草和一些不知名的鲜花，绿水湖的涛声隐约的响在
耳边，隔湖相望，云的那边一片古老的建筑模糊可见，想必就是神剑山
庄了。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
]));
          set("coor/x",-1025);

	set("coor/y",55);

	set("coor/z",80);
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
if (me->query("baishi-xie"))
		 {
          message_vision("$N往云雾缭绕的地方走了进去！\n", me);
          room = load_object(__DIR__"cyfd1");
	      me->move(room);
		 return 1;
		 }
		 else
		 {
          message_vision("$N脚下一滑，从山坡上滑落了下去！\n", me);
          room = load_object(__DIR__"cyf");
	   me->move(room);
          message_vision("$N落到路边的一棵树上弹了下来。\n", me);
               me->unconcious();
	//	 return notify_fail("");
		 return 1;
		 }
        }
	       

