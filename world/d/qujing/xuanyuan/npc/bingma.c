// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <ansi.h>
void create ()
{
  if (random(4))
    set_name("木人", ({ "mu ren ", "mu" }) );
  else
    set_name("木头人", ({ "mu ren", "mu" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一尊栩栩如生的木头人。\n");
    set("unit","尊");
  }
  setup();
}

int init ()
{
  add_action ("do_act","act");
  return 1;
}

int do_act (string arg)
{
  string *msgs = ({
   HIR "$N对着兵马俑，拿针向它全身刺去。\n"NOR,
   HIR "$N一边看着兵马俑，一边发出一道寒星。\n"NOR,
  });
  string *actions = ({
   HIY "你感觉到自己的基本针术有了进步。\n"NOR,
   HIY "你的基本针法提高了。\n"NOR,
  });
  object me = this_player();
  object ren = this_object();

  if (arg != "ren" &&
      arg != "mu ren")
  {
    tell_object(me,"你想怎样比划呢？\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"你已经太疲劳了！\n");
    me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"你正在忙着呢！\n");
    return 1;
  }
  ren->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("needle",5+random(3),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (ren->query("times")>100)
  {
    message_vision ("只见$N摇摇晃晃，轰地一下倒在地上碎了。\n",ren);
    destruct (ren);
  }
  return 1;
}

