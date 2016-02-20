//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", HIR "「" HIY "后山宫" HIR "」" NOR);
  set ("long", @LONG

蜀山派的后山宫，这里是蜀山派决议重大事件的地方，两位高手追云子、
轻云子在这里负责守护，有一些事可以问问他们。 
LONG);

   set("exits", ([ /* sizeof() == 2 */
       "south" : "/d/shushan/houshan7",
       "west" : "/d/shushan/woshi",
       "east" : "/d/shushan/liangong",
  ]));
  set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/zhuiyunzi" : 1,
                __DIR__"npc/qingyunzi" : 1,  
]));


  setup();
}






