//【蜀山派】mhxy-yushu 2001/2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","藏经阁");
  set ("long", @LONG

蜀山剑派的藏经阁，东面有一个书架，上面有些关于武功类的书。
南面书架上放着关于内功和法术类的书。你拿下一本书仔细研究。
LONG);

  set("exits", ([ 
  "west" : __DIR__"eastway4",
  ]));
  set("objects", ([
        __DIR__"obj/yijing"    : 1,
  ]));
  setup();
}

void init()
{
  add_action("do_push", "push");
}
int do_push(string arg)
{
  object me=this_player();
  if ((arg != "shujia" && arg != "书架") || !arg)
                       return notify_fail("你要推什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query("family/master_name") == "静虚老祖")
  {
   message_vision(HIM"$N被一阵五彩光芒笼罩,到了另一个地方。\n"NOR, me);
   me->move(__DIR__"midao");
  }
else 
 {
  tell_object (me,"你推书架干吗?\n");
 }
 return 1;
}








