//shushan4.c by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short",HIR "「" HIG "峨眉山" HIR "」" NOR);
  set ("long", @LONG
这里是通往蜀山派的山路，路崎岖不平，旁边就是山崖，
往下一看，不由得头晕目眩，你赶紧闭上眼睛，生怕一个不慎
，摔得粉身碎骨。
LONG);

  set("outdoors", 2);
  set("exits", ([ /* sizeof() == 2 */
  "northdown" : "/d/shushan/shushan3",
  "north" : "/d/shushan/door", 
]));

  setup();
}






