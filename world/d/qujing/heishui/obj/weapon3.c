#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("风石耙", ({ "fengshi pa", "fengshi", "pa" }) );
  init_rake(40);
  set("unit", "柄");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 450);
    set("material", "iron");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}

