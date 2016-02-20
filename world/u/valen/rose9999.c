//by tianlin 2001/5/1
#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit NECK;

//#include "message.h"

void create ()
{
  set_name("[44m[1;35m¾ÅÇ§¾Å°Ù¾ÅÊ®¾Å¶äÃµ¹å[2;37;0m", ({ "flower"}));
  set_weight(100);
  set("long","Ò»ÊøÃµ¹å£¬ËÍ¸øÎÒµÄ°®ÈË"+query("name")+"¡£\n");
  set("unit", "°Ñ");
  set("armor_prop/armor", 5);
  set("armor_prop/personality", 6);
  set("unequip_msg","$N½«"+query("name")+"ÇáÇáµØÕªÏÂÀ´¡­¡­¡£\n");
  set("wear_msg", "$N´÷ÉÏ"+query("name")+"£¬²»½ûÁ÷³ö¼¸µÎÇéÈËµÄÑÛÀá¡£\n");
  setup();
}


