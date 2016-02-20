#include <ansi.h>;
#include <room.h>

inherit ROOM;

void create()
{
    set("short", "暗室");
	set("long", @LONG
这里是一段狭长的暗室，只能一两个人容身。

LONG
);
	setup();
 
}
void init()
{
        add_action("do_pa", "pa");
        add_action("do_jump", "jump");
}
int do_pa(string arg)
{
       object me = this_player();

       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20) 
       return notify_fail("你身上负重太多，爬不下去。\n");
 
       if((int)me->query_skill("dodge",1) < 200 )  
       return notify_fail("以你目前的轻功修为，很难爬下去。\n"); 
        message_vision("$N匍匐前进，小心的爬呀爬。\n", me);
       me->move(__DIR__"gd1");
       tell_room(environment(me), me->name() + "从上面爬了下来。\n", ({ me }));
       return 1;
       
}
int do_jump(string arg)
{
       object me;
       me = this_player(); 
       if ( !arg ) return 0;
      if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20) 
       return notify_fail("你身上负重太多，无法跳过去。\n");
 
       if((int)me->query_skill("dodge",1) < 100 )  
       return notify_fail("以你目前的轻功修为，无法跳过去。\n"); 
       message_vision("$N纵身向上跳去。\n", me);
       me->move(__DIR__"houdian");
       tell_room(environment(me), me->name() + "从暗室里窜了出来。\n", ({ me }));
       return 1;
}
