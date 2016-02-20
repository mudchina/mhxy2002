// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// jiasha.c
//

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
inherit F_UNIQUE;

void init()
{
  cloth::init();
  unique::init();
}

void create()
{
   set_name(HIY"神甲胄--狮子"NOR, ({ "shen jiazhou", "jiazhou" }) );
   set("long", "此乃修罗王一平的随身宝甲，宝物一件。\n");
   set_weight(3000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "件");
     set("material", "cloth");
     set("armor_prop/armor", 90);
     set("armor_prop/spells", 50);
     set("armor_prop/dodge", 80);
     set("replace_file", "/d/obj/cloth/hufa-jiasha");
                set("value", 50000);
   }
   setup();
}


