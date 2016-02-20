#include <weapon.h>

inherit MACE;

void create()
{
  set_name("竹节鞭", ({"bamboo mace", "mace" }) );
  init_mace(15);
  set("unit", "把");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 500);
    set("material", "wood");
  }
  set("wield_msg","$N拿起$n握在手里。\n");
  setup();
}

