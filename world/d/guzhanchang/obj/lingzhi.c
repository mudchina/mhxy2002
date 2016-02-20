// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
//By tianlin@Mhxy for 2002.1.27.加物件限制

// lingzhi.c 灵芝
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//   set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(MAG "灵芝草" NOR, ({"lingzhi","ling zhi"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "浅紫色的一颗灵芝草，散发出诱人的气息。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  if (me->query("tianlin-lingzhi") >=1 )
    return notify_fail("嘿嘿嘿别做梦了！\n");

  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  message_vision(HIG "$N吃下一颗"+MAG"灵芝草"+HIG"，感到全身充满了活力！ \n" NOR, me);
  me->add("tianlin-lingzhi",1);
  destruct(this_object());
  return 1;
}


