//created by vikee
//2000.11

#include <ansi.h>
inherit ITEM;
int get_liwu(string arg);
void create()
{
  set_name(HIY"礼物台" NOR ,({"gift table","table"}));
  set("long","这是古惑仔巫师为了奖励新手做的礼物台，玩家可以在这里拿(na)礼物(liwu)。");
  set("unit", "个");
  set("value", 1000000000000);
}
void init()
{
  if (!wizardp(this_player())) 
   set("no_get","这个东西拿不起来。\n");
  add_action("get_liwu","na");
}
int get_liwu(string arg)
{
  object me = this_player();
  object lw;

 if (arg!="liwu")      return 0;
  if (me->query("newbie_liwu")) return notify_fail("你已经拿过礼物了,别太贪心哟！\n");
  message_vision("$N从礼物台上拿下一份礼物。\n" NOR, me);
  lw=new("/u/tianlin/liwu.c");
  lw=new("/wiz/bi.c");
  lw->move(me);
  me->set("newbie_liwu",1);
  return 1;
}

