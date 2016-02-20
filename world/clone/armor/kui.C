// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>;

inherit HEAD;

void create()
{
  set_name(WHT"战神天王盔" NOR, ({ "tian kui", "tiankui", "kui" }) );
 set("value", 150000);
set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long",WHT"岳飞曾经用过的战盔。\n"NOR);
    set("material", "cloth");
    set("armor_prop/armor", 10);
    set("armor_prop/personality", 1);
  }
  setup();
}

