// 神龙仙袍 by Calvin

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
  set_name(HIB"神龙仙袍"NOR, ({"xian pao", "cloth","pao"}));
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", HIB"天界的神龙专用仙袍。\n"NOR);
    set("material", "cloth");
    set("unit", "件");
    set("value", 100000);
    set("armor_prop/armor", 100);
    set("armor_prop/rake", 100);
    set("armor_prop/stick", 100);
    set("armor_prop/literate", -200);
    set("armor_prop/fork", 100);
    set("armor_prop/unarmed", -100);
    set("armor_prop/sword", 100);
    set("armor_prop/spear", 100);
    set("armor_prop/whip", 100);
    set("armor_prop/throwing", 100);
    set("armor_prop/dodge", -100);
    set("armor_prop/blade", 100);
    set("armor_prop/spells", -100);
    set ("armor_prop/force", -100);
    set("armor_prop/parry", 100);
  }
  setup();
}
