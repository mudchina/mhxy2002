// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(HIR"智慧之袍"NOR, ({"zhihui pao","cloth"}));
  set("value", 250000);
      set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",MAG "传说,穿上它就会拥有无穷的智慧。\n" NOR);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 40);
  set("armor_prop/intelligence", 10);
 }
  setup();
}

