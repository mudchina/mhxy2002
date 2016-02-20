//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","练功房");
  set ("long", @LONG

这是蜀山弟子平时修炼的地方，房中央放着小香炉，房中轻烟缭绕，
在这里练功如仙境一般。
LONG);

  set("exits", ([ 
  "west" : __DIR__"eastway3",
  ]));
  set("objects", ([
        __DIR__"npc/qingyunzi" : 1,
  ]));
    setup();
}






