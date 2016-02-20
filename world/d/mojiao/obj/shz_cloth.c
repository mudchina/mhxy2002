#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
  set_name(HIY "»Æ½ðÕ½ÅÛ" NOR, ({"golden cloth", "cloth"}));
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("unit", "¼þ");
    set("value", 400000);
    set("armor_prop/armor", 50);
  }
  setup();
}
