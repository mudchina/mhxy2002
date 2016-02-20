// by yxm@hxxt.hz
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "µÿ”¸÷Æ√≈");
set ("long", @LONG
  
            [1;31m Æ[2;37;0m
            [1;31m∞À[2;37;0m
            [1;31m≤„[2;37;0m
            [1;31mµÿ[2;37;0m
            [1;31m”¸[2;37;0m
            [1;31m÷Æ[2;37;0m
            [1;31m√≈[2;37;0m
      
LONG);
  set("exits", ([
        "out"      : __DIR__"lu6",
      ]));
  set("item_desc",([
      "men" : "\nµÿ”¸÷Æ√≈\n\n"
     ]));

  setup();
}

void init ()
{
  add_action("do_break","break");
}

int do_break (string arg)
{
  object me = this_player();

  if (arg != "men")
    return 0;

  message_vision ("$N¥Û∫»“ª…˘£¨ πæ°»´…Ìƒ⁄¡¶ª˜œÚµÿ”¸÷Æ√≈£°\n\n",me);
  if (me->query("force")<1000 ||
      me->query("mana")<1000)
  {
    me->unconcious();
    me->set("force",0);
    me->set("mana",0);
  }
  else
  {
    me->add("force",-1000);
    me->add("mana",-1000);
    message_vision ("…≤ƒ«º‰ÃÏ±¿µÿ¡—£¨ƒ„“—æ≠◊≤ø™¡Àµÿ”¸÷Æ√≈£°\n",me);
message("channel:rumor", HIY+"°æ∑ΩÁ°ø»Á¿¥∑◊Ê (rulai fo): ¥Ûµ®"+me->query("name")+"£°æ”»ªÀΩ◊‘¥Úø™¡À∫⁄∞µ÷Æ√≈£°\n"+NOR,users());
message("channel:rumor", HIR+"°æ∞¢–ﬁ¬ﬁΩÁ°øƒß∑ŒﬁÃÏ£®wu tian): ∫Ÿ∫Ÿ£¨Œ“”÷Ω´∫·––»˝ΩÁ¡À£°\n"+NOR,users());
    this_object()->recreate();
    message_vision ("\nµ´º˚£∫\n",me);
    message_vision (this_object()->query("long"),me);
    remove_call_out ("precreate");
    call_out ("precreate",10,this_object());
  }
  return 1;
}

void precreate (object me)
{
  tell_room (me,"∫‰¬°“ª…˘æﬁœÏ£¨“ª«–∂ºªπ‘≠¡À£°\n\n");
  me->create();
}

void recreate ()
{
  set ("short", "µÿ”¸÷Æ√≈");
  set ("long", @LONG
            [1;31m Æ[2;37;0m
            [1;31m∞À[2;37;0m
            [1;31m≤„[2;37;0m
            [1;31mµÿ[2;37;0m
            [1;31m”¸[2;37;0m
            [1;31m÷Æ[2;37;0m
            [1;31m√≈[2;37;0m


LONG);
  set("exits", ([
//        "out"      : __DIR__"lu6",
        "enter"  : __DIR__"diyu1",
      ]));

  setup();
}

