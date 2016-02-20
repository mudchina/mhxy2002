//created by daiyu for天地劫

#include <ansi.h>

inherit ITEM;
#define ZHANSHU "/d/newjob/tiandijie/obj/zhanshu" 
void create()
{
  set_name(HIR"魔教战书" NOR ,({"zhanshu"}));
  set("unit", "个");
  set("value", 0);
}
void init()
{
  add_action("get_look","look");
}
int get_look(string arg)
{
  object me = this_player();
  object lw;
  
  if (!userp(me))
      return notify_fail("你什么也没拿到。\n");
  if (arg!="zhanshu")  
      return 0;
      
  //清屏
  write(REF);
  cat(ZHANSHU);
  return 1;
}
