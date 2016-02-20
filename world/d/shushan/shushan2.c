//shushan2.c by yushu 2000.11
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
  "northeast" : "/d/shushan/shushan3",
  "southdown" : "/d/shushan/shushan1", 
]));

  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  string *rooms = ({
    "jianfen",
});

  object who = this_player();
  message_vision ("$N浑身颤抖着，向下一跳……\n",who);
  who->move(__DIR__+rooms[random(sizeof(rooms))]);
  return 1;
}







