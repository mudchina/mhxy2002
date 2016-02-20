//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","后山路");
  set ("long", @LONG

这里是通往蜀山派金鞭崖的山路，这里道路平坦,看来是常有人来。
听说后山上有个镇妖塔，你不禁想前去看一看。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 1 */
      "south" : __DIR__"houshan",
      "northeast" : __DIR__"houshan1",
  
 ]));

  setup();
}






