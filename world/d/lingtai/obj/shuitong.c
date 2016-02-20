// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
// hulu.c
inherit ITEM;
inherit F_LIQUID;
void create()
{
  set_name("水桶", ({"shuitong"}));
  set_weight(2000);
  set("long", "一对挑水用的大水桶。\n");
  set("unit", "个");
  set("max_liquid", 10);
// set("no_drop",1);
  set("no_sell",1);
  set("no_get",1);
  set("no_give",1);
  set("no_steal",1);
}
void init()
{
  add_action ("do_fill", "fill");
  add_action ("do_carry","carry");
  add_action ("do_pour", "pour");
}
int do_fill(string arg)
{
  if(!arg||arg!="shuitong")
     return notify_fail("你想装什么？\n");
  if(environment(this_player())->query("resource/water")!=1)
    return notify_fail("这儿没有水！\n");
  set("liquid", ([
    "type": "water",
    "name": "清水",
    "remaining": 10,
  ]));
  tell_object(this_player(),"你往水桶里装满水\n");
  return 1;
}
int do_pour (string arg)
{
  int i;
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object wan = present ("wan feng",where);
  if(!arg||arg!="gang"||!wan)
    return notify_fail ("你想把水往哪里倒？\n");
  if (! query("liquid/remaining"))
    return notify_fail ("水桶里没有水。\n");
  message_vision ("$N将$n里的"+query("liquid/name")+"倒进水缸。\n",who,me);
  set("liquid", ([
    "type": "water",
    "name": "清水",
    "remaining": 0,
  ]));
  who->add_temp("lingtai/tiaoshui",1);
  i = 4;
  i -= who->query_temp("lingtai/tiaoshui");
  tell_object(who,"你觉得有点累了\n");
  who->receive_damage("kee",20);
  who->receive_damage("sen",20);
  if (i > 0)
      message_vision ("$N告诉$n：再倒"+chinese_number(i)+"次便可。\n",
                      wan,who);
    else
    {
      message_vision ("$N告诉$n：辛苦你了，今天的水挑完了。\n",wan,who);
      who->set("lingtai_quest/done",1);
      this_object()->move(where);
     where->set("full",1);
      who->delete_temp("lingtai/tiaoshui");
    }
  return 1;
}
int do_carry(string arg)
{
   object who=this_player();
    if(!arg||arg!="shuitong")
        return notify_fail("你要挑什么?\n");
    if(who->query("lingtai_quest/quest_type")!="挑水")
       return notify_fail("晚风拦住你：不敢有劳！\n");
   if(environment(who)->query("full"))
     return notify_fail("晚风拦住你：水缸已满，你等明天吧！\n");
    if((who->query("kee")<80)||(who->query("sen")<80))
        return notify_fail("晚风拦住你：这位道兄太累了，还是先去休息吧。\n")
;
    this_object()->move(this_player());
    tell_object(this_player(),"晚风对你笑笑，就有劳这位道兄将水缸挑满了。\n"
);
    this_player()->delete("lingtai/tiaoshui");
    return 1;
}
