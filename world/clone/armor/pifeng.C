// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>;

inherit SURCOAT;

void create()
{
  set_name(HIB "王者披风" NOR, ({"pifeng", "cloth"}));
   set("value", 250000);
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",HIB"穿上他,你会感到自己像一个君王。\n"NOR);
    set("material", "leather");
    set("unit", "件");
    set("armor_prop/armor", 30);
  }
  setup();
}


