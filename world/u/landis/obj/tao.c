// mihoutao.c ÌØ´óºÅâ¨ºïÌÒ
//by tianlin 2001.5.1Õâ¸öÌÒ³ÔÁËÕÅ10µãforceºÍmanaÎÒ¾õ×ÅÕâÑùÍ¦ºÃµÄ,ÒÔÇ°µÄÄÇ¸öÌÒ³ÔÁË²ÅÒ»µã,Ã»Ê²Ã´´óÓÃ.(xixi)
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_drop","ÕâÃ´±¦¹óµÄµ¤Ò©£¬ÈÓÁË¶à¿ÉÏ§Ñ½£¡\n");
    set("no_sell","·²ÈËÄÄÀïÖªµÀ"+this_object()->query("name")+"µÄ¼ÛÖµ£¿»¹ÊÇ×Ô¼ºÁô×Å°É¡£\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(HIY"°ÙÄê"+NOR+YEL"â¨ºïÌÒ"NOR, ({"mihou tao","mihoutao","tao"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "¿Å");
    set("long", "[1;33m»Æ³È³ÈµÄÒ»¿Åâ¨ºïÌÒ£¬Õæ½ĞÈË´¹ÏÑÓûµÎ¡£[2;37;0m\n");
    set("value", 5000);
    set("drug_type", "²¹Æ·");
  }
  
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(100);
  me->add_maximum_mana(100);
  message_vision(HIG "$NÒ»¿Ú¾Í³ÔÏÂÁËÕâ¿ÅÃÖºïÌÒ£¬²îÒ»µã³ÅËÀ£¬²»¹ıµÄÈ·ÊÇºÃ³Ô£¡ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
