#include <ansi.h>
inherit ITEM;
int get_liwu(string arg);
void create()
{
set_name(HIW"小年礼物台" NOR ,({"gift table","table"}));
set("long","这是巫师为了玩家过小年做的礼物台，玩家可以在这里拿(pick)礼物(gift)。");
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
  object me = this_player();
  object lw;
  if (arg!="gift")      return 0;
if (me->query("xiaonian_gift")) return notify_fail("你已经拿过礼物了,别太贪心哟！\n");
  message_vision("$N从礼物台上拿下一份礼物。\n" NOR, me);
  lw=new("/clone/过节的礼物/小年/gift");;
  lw->move(me);
   me->set("xiaonian_gift",1);
  return 1;
}

