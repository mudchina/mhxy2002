// LLY@FYSY
#include <room.h>

inherit ROOM;
void create()
{
        set("short", "绿水湖畔");
        set("long", @LONG
绿水湖的湖水绿如蓝，水波荡漾，倒映着满天夕阳，远处的翠云峰更
美如图画。湖畔垂柳拂水，北边仿佛有一片杏林。
LONG
        );
                set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"croad2",
]));
        set("coor/x",-1055);

	set("coor/y",15);

	set("coor/z",0);
	setup();
}
init()
{
add_action("do_north", "north");
}


int do_north(string arg)

{object room, me;

  
 me = this_player();

tell_object(me, "你绕过一丛丛的柳枝，发现自己到了一片杏花丛中...\n\n");
   room=find_object(__DIR__"ctree");
if(!objectp(room)) room=load_object(__DIR__"ctree");

me->move(room);
return 1;

}