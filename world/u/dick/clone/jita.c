inherit ITEM;
#include <ansi.h>
int query_autoload() { return 1; }
void create()
{
    object me
;
  me = this_player();
  if (me->query("id")!="super")
  set_name("天星送给"+me->query("id")+"的吉他",({"jita"}));
  else
  set_name(HIB"天星的寂寞吉他"NOR,({"jita"}));
  set("long","这是天星专用的电吉他，你可以弹奏(play)它。\n");
  set("no_give","这个东西不能随便乱给人的！\n");
  set("no_drop","这个东西不能随地乱丢的！\n");
  setup();
}
void init()
{
  add_action("do_play","play");
}
int do_play(string arg)
{
      int i;
    object me;
    me = this_player();
    if (!arg||arg!="jita")
    return notify_fail("你想弹什么？\n");
    message_vision(HIG"$N深情的弹起了吉他，口中脉脉的唱道：“我是一个爱的梦游人哪~~~~~~~！”\n"NOR,me);
   for(i=0; i<sizeof(all_inventory(environment(this_player()))); i++) {
if ( !living(all_inventory(environment(this_player()))[i]) || all_inventory(environment(this_player()))[i]==this_player() ) continue;
tell_object(all_inventory(environment(this_player()))[i], HIR"你听到天星的歌声后，只觉得全身顿时软了下来，心里舒畅得不得了！\n"NOR);
 all_inventory(environment(this_player()))[i]->set("env/immortal",0);
}
return 1;
}
