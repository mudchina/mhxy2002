// changan wusheng
// xuanya3.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "火云断崖上");
  set ("long", @LONG

火云断崖风光秀丽，当真是好去处！前方一个山洞，洞里有祥
云绕绕，隐有红光。崖壁上多是青苔锈葛，看上去异常的滑手。
崖上有兽鸣阵阵，空山回音不绝。
LONG);
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"huoyunwai",
  "down" : __DIR__"xuanya2",
]));
	set("outdoors", 1);
  setup();
}

