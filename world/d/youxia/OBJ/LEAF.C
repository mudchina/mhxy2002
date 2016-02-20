// created 17-06-2001 海上飘(piao)


#include <ansi.h>

inherit ITEM;

         string *names = ({
HIR"梅花"NOR, 
HIY"梅花"NOR, 
HIW"梅花"NOR, 
HIC"梅花"NOR, 
HIM"梅花"NOR,
HIB"梅花"NOR, 
});
void create()
{
  set_name(names[random(sizeof(names))], ({"leaf"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "朵");
    set("long", "万梅山庄梅林中的梅花。\n");
    set("value", 1000);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="wuhua guo" && arg!="leaf") 
      return notify_fail("你要吃什么？\n");
  
  
  me->set("food", (int)me->max_food_capacity()+random(100));
  me->set("water", (int)me->max_water_capacity()+random(100));
  message_vision(HIG "$N掰开一朵梅花往嘴里一放。\n" NOR, me);
  tell_object(me, "顿时你觉得口中生津，一股甜润自上而下如醍醐灌顶。\n");
  destruct(this_object());
  return 1;
}
