// by qingchun(充电器) 6/30/2001
// pidai.c 特制皮带

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(YEL "特制牛皮带" NOR, ({"pidai", "pi", "dai"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "条");
    set("long", "一条纪念红军长征的特制皮带，好像是用特制的原料制作的，可以（eat
）试一试。\n");
    set("drug_type", "补品");
    set("value",0);
  }

  setup();
}

void init()
{
  if (!wizardp(this_player()))
 {
    set("no_get","嘿嘿！不要做白日梦了 \n");
    set("no_give","现在不是长征时期，不要你推我让了！ \n");
    set("no_drop","这么宝贵的纪念品，扔了对不住党啊！ \n");
    set("no_sell","还是自己留着吧。\n");
  }            
  add_action("do_eat", "eat");}


int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("你要吃什么？\n");
if (me->query("changzheng_liwu")) return notify_fail("你已经体验过了长征的辛苦.\n");


  me->set("food", (int)me->max_food_capacity());
  switch (random(3))
  {
    case 0:
    {
      message_vision(HIG "$N皱了皱眉头，吃下这条特制皮带，想起红军的千辛万苦！
                          $N得到了10000点潜能，10000武学！恭喜了！\n" NOR, me);
      me->add("potential", 10000);
      me->add("combat_exp", 10000);
      break;
    }
    case 1:
    {
      message_vision(HIW "$N毫不犹豫的吃完了这条皮带！显示了一种大无畏的精神！
                           $N得到了5000点潜能，10年道行！恭喜了！ \n" NOR, me);
      me->add("potential", 5000);
      me->add("daoxing", 10000);
      break;
    }
    case 2:
    {
      message_vision(RED "$N慢慢的将这条皮带吃完，心中充满了对红军战士的敬重！
                           $N得到了5000点武学，10年道行！恭喜了！\n" NOR, me);
     me->add("combat_exp", 5000);
      me->add("daoxing", 10000);

      
      break;
    }
  }
  me->set("changzheng_liwu",1);
  destruct(this_object());
  return 1;
}

