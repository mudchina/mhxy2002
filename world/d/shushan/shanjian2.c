//【蜀山派】mhxy-yushu 2001/2
#include <ansi.h>
inherit ROOM;
int do_dive();
void create ()
{
  set ("short", "山涧");
  set ("long", @LONG

这里有一个小的水潭，可能是崖上的瀑布流下来的水长年累月的流不
出去而变成这个水潭吧，你绝望的看了看四周，全都是悬崖峭壁，看
来想出去不可能了，只有祈祷有奇迹发生。
LONG);

  set("exits", ([      
         "south" : __DIR__"shanjian",
 ]));
 setup();
}
void init()
{
    add_action("do_dive", "dive");
}
int do_dive()
{   
   object me, zhou;
   object ridee;
   me=this_player();
   ridee=me->ride();
   if(( !(zhou=present("bishui zhou", me))
		||(string)zhou->query("unit")!="张")
		&& (string)me->query("family/family_name")!="龙宫"
		&& (string)me->query("family/family_name")!="东海龙宫")
                           return notify_fail("你一个猛子扎到水里．．．\n"+
		  "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

  if (ridee && ridee->query("under_water")) {
  message_vision(HIY"$N一拍$n的头，连人带马跃入水中。\n"NOR,me,ridee);
  ridee->move(__DIR__"midao");
  }
  else  message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, me);
  me->move(__DIR__"midao");
  message_vision(HIW"$N借助水流的冲击不知不觉的来到另一个地方。\n"NOR,me);
  message_vision(HIR"$N的头突然一阵晕旋,顿时失去了知觉。\n"NOR,me);
  me->unconcious();
  return 1;
}

