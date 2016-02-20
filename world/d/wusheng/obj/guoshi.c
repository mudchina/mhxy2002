// guoshi.c 万年无名果

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIM"万年"NOR+HIG"无名果"NOR , ({"wuming guo", "guo", "guoshi"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗在树上结了上万年的果实。\n");
    set("value", 800);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
  call_out ("becoming_old",1800);
}

void becoming_old ()
{
  object me = this_object();
  object where = environment (me);
  object dan = new (__DIR__"danbad");

  dan->move(where);
  destruct (me);
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="wuming guo" && arg!="guo") 
    return 0;
  
  me->set("food", (int)me->max_food_capacity()*5+random(120));
  me->set("water", (int)me->max_water_capacity()*5+random(120));
  message_vision(HIG "$N捏起一颗万年无名果送进嘴里吞下。\n" NOR, me);
  tell_object(me, "顿时你觉得腹中生热，飘飘欲仙！\n");
  destruct(this_object());
  return 1;
}

