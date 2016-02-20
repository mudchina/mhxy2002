//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","台阶");
  set ("long", @LONG

由青石铺成的台阶，湿漉漉的台阶上面长满了藓苔，你小心的
走着，就怕一不小心滑倒，再往前走就是“金鞭崖”了。
LONG);

  set("outdoors", 2);
  set("exits", ([ 
       "down" : __DIR__"houshan5",
      "north" : __DIR__"jby",
 ]));

  setup();
}






