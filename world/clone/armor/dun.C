// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
  set_name(MAG"ÓÂÕßÖ®¶Ü"NOR, ({"yongzhe dun", "dun"}));
  set("value", 100000);
   set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "¼þ");
   set("value", 100000);
   set("material", "wood");
   set("armor_prop/armor", 25);
   set("armor_prop/dodge", -2);
  }
  set("no_sell",1);
  setup();
}
