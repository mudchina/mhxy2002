#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "灵界");
  set ("long", @LONG

四周一片黑暗,到了这里,便于外界失去了任何联系,你只有在
这无边无际的黑暗中到处摸索,不停前进了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lingjie1",
]));

  setup();
}

void close_up()
{
        object uproom;

        if( !query("exits/out") ) return;
	message("vision", "轰隆一声,压龙石回到了原位。\n", this_object());


        if( uproom = find_object(__DIR__"rukou") ) 
        {
		message("vision", "轰隆一声,压龙石回到了原位。\n", uproom);
                uproom->delete("exits/enter");
        }

        delete("exits/out");
}

