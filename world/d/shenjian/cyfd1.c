// LLY@FYSY
#include <room.h>
inherit ROOM;
int do_dive(string arg);
void create()
{
        set("short", "翠云峰顶");
        set("long", @LONG
这里三面皆是云雾，只面湖一边可以看清楚一点，仔细一看，
这里好象就是船上十字所指之处了。
LONG
        );
        set("item_desc", ([
                "lake": "从这里可以（ｄｉｖｅ）跳下去潜到湖底。\n",
                "water" : "从这里可以（ｄｉｖｅ）跳下去潜到湖底。\n",
                "绿水湖" : "从这里可以（ｄｉｖｅ）跳下去潜到湖底。\n"
        ]) );

         set("coor/x",-1025);

	set("coor/y",65);

	set("coor/z",80);
set("no_magic",1);
	setup();
}
void init()
{

add_action("do_dive","dive");
}
int do_dive(string arg)
{
        object room;
        object me;
                me = this_player();
		message_vision("$N纵身向着绿水湖跳了下去！\n", me);
          room = load_object(__DIR__"hudi");
	      me->move(room);
//		 return notify_fail("");		
		 return 1;		
        }
	       

