//By tianlin@Mhxy for 2002.3.11
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", HBRED+HIY"朝阳门");
  set ("long", 

"\n高墙巍峨，长梁雕龙，飞檐画凤，这里就是"HIY"“朝阳门”"NOR"。往\n"
"里就是皇宫大门了，一般的百姓到此截然止步，不敢擅自逾\n"
"越皇家禁地。\n\n"
);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/weishi" : 2,
  ]));
  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : "/d/city/xuanwu-n1",
"north" : __DIR__"damen",
// "east" : "/d/city/datang",
]));

  setup();
}


