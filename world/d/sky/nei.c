// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "内殿");
  set ("long", @LONG
这里就是玉帝的宝座了,座上那人衣着十分华丽,但隐隐给人庸俗的感觉,
尤其是那倨傲的神气,让人看着就想扁他一顿.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"dadian.c",
]));


  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yudi" : 1,
]));

  setup();
}

