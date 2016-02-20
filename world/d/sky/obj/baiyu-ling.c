// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// dagger.c : an example weapon

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
   set_name(HIW"白玉令"NOR, ({"baiyu-ling"}));
   set_weight(10);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "支");
     set("long", "玉帝信物,通体雪白,触手极寒,相传可凭此调动九天诸神.\n");
     set("value", 50);
     set("material", "gold");
     set("no_drop",1);
     set("no_sell",1);
     set("no_put",1);
     set("no_get",1);
   }
   init_dagger(4);

// These properties are optional, if you don't set them, it will use the
// default values.

   set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
   set("unwield_msg", "$N将手中的$n藏入怀中。\n");

// The setup() is required.

   setup();
}
