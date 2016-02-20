#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
  set_name( HIR"ºìÑ¥×Ó"NOR, ({ "red shoes", "pixue", "xue" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "Ë«");
    set("long", "Ò»Ë«ºìÉ«³¤Í²Æ¤Ñ¥¡£\n");
    set("value", 50);
    set("material", "boots");
    set("armor_prop/dodge", 1);
  }
  setup();
}

