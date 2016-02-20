//By tianlin@mhxy for 2001.9.20修改
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
  set_name(YEL"千年人参王"NOR, ({"qiannian renshen","renshenwang","renshen"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "这是一颗千年的人参王，十分珍贵。\n");
    set("value", 2000000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_eat(string arg)
{
  int qixue, jingshen, buman;
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
    qixue = me->query("eff_kee") - me->query("kee");
    buman = qixue * 50 / (int)me->query_skill("force");
    if(buman < 1)
         return notify_fail(WHT"你现在没有掉"NOR+HIR"气血"NOR+WHT"啊。\n"NOR);

    jingshen = me->query("eff_sen") - me->query("sen");
    buman = jingshen * 50 / (int)me->query_skill("force");
    if(buman < 1)
         return notify_fail(WHT"你现在没有掉"NOR+HIC"精神"NOR+WHT"啊。\n"NOR);

  me->add("kee",500);
  me->add("sen",500);
  message_vision(HIY "$N吃下一颗"NOR+YEL"千年人参"NOR+HIY",感觉自己又充满了力量！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
