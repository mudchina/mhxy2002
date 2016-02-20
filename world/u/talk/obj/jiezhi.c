// by happ@YSZZ

#include <armor.h>
#include <ansi.h>

inherit CLOTH;
//#include "chk_owner.c"

void create()
{
   set_name(HIC"白金钻戒"NOR, ({ "zuanjie" }) );
   set_weight(400);
                set("long",HIM "这是南瓜为他老婆亲手定做的结婚戒指。\n" NOR);
   if( clonep() )
   set_default_object(__FILE__);
   else {
     set("unit", "个");
      set("no_sell",1);
      set("no_drop",1);
       set("value",12000);
     set("material", "diamond");
     set("armor_prop/armor",120);
  }
   setup();
}
