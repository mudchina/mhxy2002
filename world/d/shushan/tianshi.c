//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","天师洞");
  set ("long", @LONG

说是天师洞，实际上这不是一个石洞，只是老祖取得名字而已
听说天师洞里有一个蜀山的剑神，不知道怎么才能见到他。
墙壁(wall)看起来很特别,不知道打(da)碎会怎么样。
LONG);
   set("exits", ([      
       "north" : __DIR__"fangning",
       "south" : __DIR__"sanhuang",
        "east" : __DIR__"eastway1",
        "west" : __DIR__"westway1",
  
  ]));
   set("objects", ([ 
      __DIR__"npc/zhangmen" : 1,
   ]));
  set("no_magic", 1);
  setup();
}
void init()
{
  add_action("do_da", "da");
}

int do_da (string arg)
{
  object me = this_player();
  if(me->query("shushan/jianshen_cast")) 
            return notify_fail("你打墙壁干吗？\n");
  if ((arg != "墙" && arg != "wall") || !arg)
            return notify_fail("你要打什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if((int)me->query_skill("xianfeng-spells", 1) > 99) {
  message_vision(HIG"$N猛打墙壁，$N突然间不见了。\n"NOR, me);
  me->move(__DIR__"xianjing");
  }
else 
 {
  tell_object (me,"你不怕手阵碎吗？\n");
 }
 return 1;
}









