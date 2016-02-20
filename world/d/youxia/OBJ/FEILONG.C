// feilong.c, created 17-06-2001 海上飘(piao)


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(WHT "飞龙枪" NOR, ({ "feilong spear","qiang","spear" ,"feilong" }));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
    set("value", 54000);
    set("material", "steel");
    set("long", "一柄上下全由玄钢做成长枪，上面刻着一条栩栩如生飞龙，顾得名“飞龙枪”。\n");
    set("wield_msg", "$N横握起一柄$n，果然威风凛凛。\n");
    set("unwield_msg", "$N收起$n，想顺手摸了一下上面刻的飞龙。\n");
  }
  init_spear(160);
  setup();
}

