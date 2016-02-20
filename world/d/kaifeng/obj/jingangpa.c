//by tianlin 2001.7.31

#include <ansi.h>
#include <weapon.h>

inherit RAKE;

void create()
{
  set_name(HIY"九转"NOR+CYN"七星"NOR+HIC"耙"NOR, ({ HIR"jingang pa"NOR, "pa","rake" }) );
  set_weight(19000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 138000);
    set("material", "iron");
    set("long", "这是一柄金刚不坏的耙子。\n");
    set("wield_msg", "$N抡起一柄$n，呼地一声举过头顶。\n");
  }
  init_rake(175);
  setup();
}


