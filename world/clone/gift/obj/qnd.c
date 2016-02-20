#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
 set_name(HIW "潜能丹" NOR, ({"qianneng dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
   set("long", "引发人体潜力的神奇丹药。\n");
    set("no_sell", 1);
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
    
  if (!id(arg))
    return notify_fail("你要吃什么？\n");

    message_vision(HIW"$N吃下一颗潜能丹，顿时觉得胸中气血翻腾。\n"NOR, me);  
  
 me->add("potential", me->query("potential")/100+1000);

  destruct(this_object());
  return 1;
}
