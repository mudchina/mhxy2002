//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","蜀山御天宫");
  set ("long", @LONG

蜀山御天宫是蜀山剑派开山祖师静虚老祖修炼的地方,
是蜀山派最秘密地方，一般蜀山派弟子，没有很好练功
资质是不知道这里的,而且蜀山剑圣教徒地极为严格。
LONG);

  set("exits", ([
   "west" : __DIR__"sleeproom",
   "south" : __DIR__"midao",
  ]));
  set("objects", ([         
     __DIR__"npc/laozu" : 1,
  ]));
  setup();
}
