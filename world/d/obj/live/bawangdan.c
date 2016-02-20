
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松，"+HIR"龙虎霸王丹"NOR+"从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIR "龙虎霸王丹" NOR , ({"longhu dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗深红色的丹丸，随非香气扑鼻，但一看就知决非凡品。\n");
    set("value", 1500000);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="longhu dan")	return 0;
  
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana")*2-1);
  me->set("force", (int)me->query("max_force")*2-1);
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N轻轻掰开一颗"+HIR"龙虎霸王丹"NOR+HIG"送入嘴中，一时间香气四溢。
只见$N突然跌坐在地上，半晌，蓦然腾空而起，精神倍增，！\n" NOR, me);
  destruct(this_object());
  me->start_busy(2);
  return 1;
}

