// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>
#include <ansi.h>

inherit HEAD;
inherit F_UNIQUE;

void create()
{
  set_name(HIY"冲天冠" NOR, ({ "tian guan", "guan" }) );
  set_weight(700);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","一顶彩霞编织的金色软冠，上面绣着九条五爪金龙。\n");
    set("value", 800);
    set("armor_prop/armor", 10);
    set("armor_prop/spells", 30);
    set("armor_prop/dodge", 30);
    set("replace_file", "/d/qujing/tianzhu/obj/longguan");
    set("material", "silk");
    set("armor_prop/personality", 1);
  }
  setup();
}

