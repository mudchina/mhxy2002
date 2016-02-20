//By tianlin@mhxy for 2002.1.2.
#include <ansi.h>
#include <weapon.h>

inherit MACE;

void create()
{
         set_name(HIB "惊魂"HIR"夺魄"HIY"锏" NOR, ({"jinghun mace","mace","duopo mace","jinghun","duopo"})); 
         set_weight(10000);
      if( clonep() )
              set_default_object(__FILE__);
      else {
              set("unit", "柄");
              set("value", 80000);
              set("rumor_msg",1);
              set("no_sell",1);
              set("no_get",1);
              set("no_give",1);
              set("no_drop",1);
              set("is_monitored", 1);
              set("material", "gold");
              set("long", HIR"这是一把无敌的锏。\n"NOR);
              set("wield_msg", "$N抽出了$n，喃喃道：锏儿，锏儿，再请你一回！\n");
              set("unwield_msg", "$N收起了$n，长吁了一口气道：宝锏果然又显雄风！\n");
  }
  
     init_mace(100+random(100));
     setup();
}

