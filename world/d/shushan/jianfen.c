//jianfen.c by yushu 2000.11

inherit ROOM;
#include <ansi.h>
void init();

void create ()
{
  set ("short",HIR "「"HIY "剑坟" HIR "」" NOR);
  set ("long", @LONG
山路绕过一个轰然作响的山涧，这里地势低平。这里正是蜀山派
的剑坟。四周全是世上的绝世好剑，可惜全都断了，轻云子负责
看守这里。
LONG);

         set("exits", ([ 
               "up"   : __DIR__"shushan2",
      ]));
  set("objects", ([
        __DIR__"npc/lingyunzi"   : 1,
      ]));
     setup();
}



