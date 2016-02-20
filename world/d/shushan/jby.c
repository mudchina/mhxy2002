//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <room.h>
void create ()
{
  set ("short", "金鞭崖");
  set ("long", @LONG

这就是蜀山派的金鞭崖，远远望去仿佛能看到太阳升起的地方，
真是“居高临下”阿。你向下望去，心头突然一震，下面是看不见
底的深渊。万一失足掉下去就会跌个粉身碎骨。你不禁向后推了几步。
右面是蜀山禁地，有蜀山地子看守。
LONG);

  set("outdoors", 2);
  set("exits", ([ 
       "south" : __DIR__"houshan6",
         "east" : __DIR__"jindi",
        "west" : __DIR__"feipu",

 ]));

  setup();
}

void init ()
{
  add_action ("do_jump","jump");
}

int do_jump (string arg)
{
  
  object who = this_player();
  message_vision("$N浑身颤抖着，向下一跳……\n",who);
  message_vision ("$N从悬崖上跳了下来，差一点跌死。\n",who);
  who->unconcious();
  who->move(__DIR__"shanjian");
  return 1;
}
