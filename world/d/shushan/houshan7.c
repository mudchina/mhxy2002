//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIR "「" HIG "台阶" HIR "」" NOR);
  set ("long", @LONG

由青石铺成的台阶，湿漉漉的台阶上面长满了藓苔，你小心的
走着，就怕一不小心滑倒，再往前走就是“后山宫”了。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 1 */
       "down" : "/d/shushan/houshan6",
      "north" : "/d/shushan/hsg",
 ]));

  setup();
}






