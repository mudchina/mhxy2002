// changan wusheng
// baiyun0.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "火云洞外");
  set ("long", @LONG

一个三个人高，两个人宽的山洞口，洞口上还用正楷写了三个
大字——〖火云洞〗。洞内股股热风吹出，风中还带着丝丝腥味，
不时传来一阵兽鸣！？？？莫非有怪兽？！？！
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "enter" : "洞中红光闪闪，什么也看不清楚。\n",
]));
  set("exits", ([ /* sizeof() == 3 */
  "enter" : __DIR__"huoyun0",
  "south" : __DIR__"xuanya3",
]));

  setup();
}

