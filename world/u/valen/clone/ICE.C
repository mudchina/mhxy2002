// mhsj@gslxz 2001.6.26

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","������һ�ɣ�����ܴ�ָ�们�䣡\n");
    set("no_give","��ô���Ķ��������������ˣ�\n");
    set("no_drop","��ô����Ķ��������˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIW "�����" NOR , ({"icecream", "ice"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�ݴ��ı���ܣ����滹��һ��ӣ�ң���΢���ŵ�Щ��������\n");
    set("value", 500000);
    set("drug_type", "��Ʒ");
  }
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="ice" && arg!="icecream")   return 0;
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("water", (int)me->max_water_capacity());
  me->set("food", (int)me->max_food_capacity());
  message_vision("$N��������ҧ��һ�ڣ���ʱһ������������Ƣ��
ֻ��$N���������������Σ��������о�����ˣ�\n", me);
  return 1;
}
