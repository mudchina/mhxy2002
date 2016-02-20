//birthday_cake.c 
#include <ansi.h>
inherit ITEM;

int do_eat(string);
void init();

void init()
{
add_action("do_eat", "eat");
}

void create()
{
set_name(HIR"生日蛋糕"NOR, ({"cake", "birthday_cake"}));
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "块");
set("long", "这是你的生日礼物，祝你生日快乐。\n");
set("value", 0);
      set("no_sell",1);
      set("no_give",1);
      set("no_drop",1);
      set("no_get",1);
}
setup();
}

int do_eat(string arg)
{
int age;
int qn;
int wx;
object me = this_player();

if(this_object()->query("owner") != me)
  return notify_fail("这不是你的生日蛋糕。\n");
if (!id(arg))
return notify_fail("你要吃什么？\n");
age = (int)me->query("mud_age");

qn=age/10+random(2000);
wx=age/40+random(5000);
if (qn>50000) 
   qn=50000;
if (qn<5000)
   qn=5000;
if (wx>50000)
   wx=50000;
if (wx<5000)
   wx=5000;
me->add("combat_exp", qn);
me->add("potential", wx);
message_vision("$N拍了拍自己的肚皮，有点爽 !\n", me);
destruct(this_object());
return 1;
}

