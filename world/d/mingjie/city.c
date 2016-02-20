#include <ansi.h>
inherit ROOM;                                                        
                                                                     
void create ()                                                       
{                                                                    
  set ("short", HIM"海修达因城"NOR);                                   
  set ("long", @LONG                                                 
这里是海修达因城,是冥界的入口，你想进冥界就要先把这里给破坏掉
城中心有一根柱子，你真的想打碎它么？(break)。                                           
LONG);                                                          
                                                                     
    set("exits", ([ /* sizeof() == 1 */                              
]));                                                                                                                          

  setup();                                                           
}

void init()
{
        add_action("do_break", "break");
}

int do_break(string arg)
{
        object room, ob;
        object me = this_player();

        if (query("exits/down"))
                return notify_fail("柱子已经被打破了。\n");
        if (!arg || (arg != "hole"))
                return notify_fail("你要打碎什么？\n");

        if(!( room = find_object(__DIR__"jin")) )
                room = load_object(__DIR__"jin");
        if(objectp(room))
        {
                room->set("long","这里就是冥界的入口了。\n");                                      
                           set("exits/down", __DIR__"jin");
                message_vision("$N用尽全力，把柱子打碎！\n", this_player());
                write(CYN"冥界的路口打开了，快下去把！”\n");

        }

        return 1;
}