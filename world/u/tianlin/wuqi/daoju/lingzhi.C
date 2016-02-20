
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIR"万年灵芝"NOR, ({"wannian lingzhi","wannian","lingzhi"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "这是一颗万年的灵芝，非常珍贵。\n");
    set("value", 2000000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_mana(20);
  message_vision(HIR "$N吃下一颗万年灵芝，只觉得法力无边，都快无敌了！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
