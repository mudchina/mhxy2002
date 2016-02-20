//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short",HIR "「" HIY "练功房" HIR "」" NOR);
  set ("long", @LONG

这是追云子和轻云子练功的地方，房中央放着小香炉，房中轻烟缭绕，
在这里练功如仙境一般。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"hsg",
]));

  setup();
}






