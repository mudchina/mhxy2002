//By tianlin@mhxy for 2001.9.20
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
  set_name(HIC"天山雪莲"NOR, ({"tianshan xuelian","tianshan","xuelian"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "这是千年罕见的一颗雪莲，十分神奇。\n");
    set("value", 2000000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_eat(string arg)
{
  int force, mana;
  object me = this_player();
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  force = (int)me->query("max_force");
  mana  = (int)me->query("max_mana");

  me->set("force",force*2);
  me->set("mana",mana*2);
  message_vision(HIY "$N吃下一颗天山雪莲，只觉着你的法力突飞猛进，增强了许多！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
