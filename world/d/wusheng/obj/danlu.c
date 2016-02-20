// danlu.c 九脚丹炉

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name(HIW"九脚丹炉"NOR, ({ "jiujiao danlu", "danlu" }) );
  set_weight(300000);
  set_max_encumbrance(8000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "鼎");
    set("long", "这是一鼎武圣门用来盛仙丹灵药的九脚丹炉。\n");
    set("value", 2000);
  }
}

int is_container()
{
  return 1;
}

void init ()
{
  remove_call_out ("smoking");
  if(userp(this_player())) {
  call_out ("smoking",3+random(3),this_object());
  add_action ("do_enter", "penetrate");
  add_action ("do_enter", "enter");
  add_action ("do_enter", "fly");
  add_action ("do_enter", "dive");
  add_action ("do_enter", "teleport");
  add_action ("do_enter", "jump");
  add_action ("do_enter", "plunge");
  }
}

int do_enter (string arg)
{
  object who = this_player();
  if (arg != "tong danlu" && arg != "danlu")
    return 0;

  message_vision ("$N潜身往丹炉里一跃，袅袅青烟中$N呼地一声不见了。\n",who);
  who->move("/d/wusheng/indanlu");
  who->start_busy(1);
  message_vision ("$N象青烟一样从丹炉里飘了过来。\n",who);
  if (who->query("combat_exp") < 5000)
      who->unconcious();
  return 1;
}

void smoking (object me)
{
  object where = environment (me);
  tell_room (where,"铜丹炉冒出袅袅的青烟。\n");
}
