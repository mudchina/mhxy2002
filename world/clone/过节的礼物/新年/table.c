#include <ansi.h> 
inherit ITEM;
int get_liwu(string arg);
void create()
{
  set_name(HIW"新年礼物台" NOR ,({"gift table","table"}));
  set("long","过新年了该发礼物了，玩家可以在这里拿(pick)礼物(gift)。");
  set("unit", "个");
  set("value", 1000000000000);
}

void init()
{
  if (!wizardp(this_player())) 
    set("no_get","这个东西拿不起来。\n");
  add_action("get_gift","pick");
}

int get_gift(string arg)
{
  object me = this_player(); // 设定me的指代物品
  object lw; //设定物品简单称呼                          
  if (arg!="gift")      return 0;
  if (me->query("newyear_gift")) return notify_fail("你已经拿过礼物了,别太贪心哟！\n"); //"标记"限制
  if (me->query("combat_exp") <= 10000) return notify_fail("你的武学是不是有点。。。。\n"); //武学限制
  message_vision("$N从礼物台上拿下一份礼物。\n" NOR, me); //拿下礼物时的动作描述
  lw=new("clone/过节的礼物/新年/gift"); //礼物路径    
  lw->move(me); //礼物所给的对象看前面的me的指代
  me->set("newyear_gift",1); //做标记
  return 1;
}