//shushan2 by yushu@SHXY 2000.12
#include <armor.h>
inherit SURCOAT;
void create()
{
  set_name("龙纹披风", ({"longwen pifeng", "pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件龙纹披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value",7000);
    set("armor_prop/armor", 30);
  }
  setup();
}


