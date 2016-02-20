#include <room.h>

inherit ROOM;

void create()
{
	set("short", "断肠崖");
	set("long", @LONG
这里是绝情谷后山峰顶，人迹鲜至，站到崖前，俯视深谷，但见灰雾
茫茫。
LONG
	);
set("exits", ([
                "southdown" : __DIR__"sl3",
	]));
 

        set("outdoors", "襄阳");
	setup();
 
}
void init()
{
     add_action("do_look", "look");
        add_action("do_jump", "jump");
}
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "ya") return 0;
             write(
             "你仔细打量四周。发现在不远处有一块突出来的峭壁，可以勉强容身。\n"
             );
             this_player()->set_temp("jqg_look1", 1);
             return 1;
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if (arg != "qiaobi" ) return 0;
       if ( !arg ) return 0;
/*
       if (!me->query_temp("jqg_look1"))
        return notify_fail("你要往那里跳？\n");
*/
        
       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       return notify_fail("你身上负重太多，无法跳过去。\n");
 
      if((int)me->query_skill("dodge",1) < 100 )  
       return notify_fail("以你目前的轻功修为，无法跳过去。\n"); 
       message_vision("$N纵身向前面的峭壁跳了过去。\n", me);
       me->move(__DIR__"qb");
       tell_room(environment(me), me->name() + "从断肠崖跳了过来。\n", ({ me }));
       me->delete_temp("jqg_look1");
       return 1;
}
