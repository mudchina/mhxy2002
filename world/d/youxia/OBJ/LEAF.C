// created 17-06-2001 ����Ʈ(piao)


#include <ansi.h>

inherit ITEM;

         string *names = ({
HIR"÷��"NOR, 
HIY"÷��"NOR, 
HIW"÷��"NOR, 
HIC"÷��"NOR, 
HIM"÷��"NOR,
HIB"÷��"NOR, 
});
void create()
{
  set_name(names[random(sizeof(names))], ({"leaf"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "��÷ɽׯ÷���е�÷����\n");
    set("value", 1000);
    set("no_sell", 1);
    set("drug_type", "��Ʒ");
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
      return notify_fail("��Ҫ��ʲô��\n");
  
  
  me->set("food", (int)me->max_food_capacity()+random(100));
  me->set("water", (int)me->max_water_capacity()+random(100));
  message_vision(HIG "$N����һ��÷��������һ�š�\n" NOR, me);
  tell_object(me, "��ʱ����ÿ�������һ���������϶����������ඥ��\n");
  destruct(this_object());
  return 1;
}