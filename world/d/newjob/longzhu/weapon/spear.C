// 龟仙神枪 by Calvin

#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIW "龟仙神枪" NOR, ({ "gueixian spear","qiang","spear" }));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 1000);
    set("material", "gold");
    set("long", "此枪以是龟仙岛主人专用,是杆神枪。\n");
    set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花,搞的天地都为之动摇。\n");
  }
  init_spear(120);
  setup();
}
