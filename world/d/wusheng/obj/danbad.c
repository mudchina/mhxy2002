//by tianlin@mhxy 2001.7.4

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( "[1;30mÒ»¿Å»µÁËµÄÎŞÃû¹û[2;37;0m" , ({"wuming guo", "guo"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¿Å");
    set("long", "Ò»¿Å³¤Ã¹µÄÎŞÃû¹û£¬ÉÏÃæÈ«ÊÇÂÌÃ«¡£\n");
    set("value", 0);
    set("no_sell", 1);
    set("drug_type", "²¹Æ·");
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
  if (arg!="wuming guo" && arg!="guo") 
    return 0;
  
  tell_object(me, "»µÒ©»¹ÄÜ³ÔÂğ£¿\n");
  return 1;
}

