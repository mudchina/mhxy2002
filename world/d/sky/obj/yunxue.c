// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
#include <ansi.h>

inherit BOOTS;
inherit F_UNIQUE;

void create()
{
  set_name( HIG "魅影神靴" NOR, ({ "yun xue", "yunxue", "xue" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "一双看不出质地的靴子。\n");
    set("value", 120);
    set("material", "boots");
    set("no_sell",1);
    set("material", "boots");
    set("armor_prop/dodge", 30);
    set("armor_prop/spells",15);
    set("replace_file", "/d/qujing/tianzhu/obj/yunxue");
  }
  setup();
}

