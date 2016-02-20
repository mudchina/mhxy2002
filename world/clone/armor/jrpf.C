// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>;

inherit SURCOAT;

void create()
{
  set_name(MAG "锦绒披风" NOR, ({"pifeng", "cloth"}));
   set("value", 250000);
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",MAG"真丝制成的非常华丽的披风。\n"NOR);
    set("material", "leather");
    set("unit", "件");
    set("armor_prop/armor", 40);
  }
  setup();
}


