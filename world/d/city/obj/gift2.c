//by yushu 2001.1
#include <ansi.h> 
inherit ITEM;    
inherit F_FOOD;
int do_eat(string arg); 
void create()
{
  set_name(YEL "粽子" NOR,({"zongzi"})); 
  set("long","这是巫师送给玩家的端午节的礼物。"); 
  set("unit","个"); 
  set("value", 0); 
  setup(); 
}
void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这个东西拿不起来。\n"); 
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","这东西不能卖。\n");
   }
    if(this_player()==environment())
      add_action("do_eat", "eat");
}
int do_eat(string arg)
{
  object me=this_player();
  if (!arg && arg!="zongzi") return notify_fail("你要吃什么?\n"); 
  if (me->query("duanwu01_liwu")) return notify_fail("你已经吃过粽子了，吃多了要坏肚子的。\n");
  message_vision("$N三口两口将粽子吞下,$N得到"HIR+BLINK"一万武学，一万潜能，一个人参果"NOR"的奖励，请"HIW+BLINK"save"NOR"后"HIW+BLINK"quit"NOR"再连线进入。\n" NOR,me); 
  me->add("potential",10000);
  me->add("combat_exp",10000);
  me->add("rsg_eaten",1); 
  me->set("duanwu01_liwu",1);
  destruct(this_object());
  return 1; 

}
