#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE; 
inherit SWORD;

void create()
{
    set_name(HIY "真武剑" NOR, ({ "zhenwu jian","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
        	set("value", 0);
        	set("no_drop", "1");
        	set("no_get", "1");
                        set("no_sell", "1");
                         set("no_give", "1");
                          set("no_put", "1");
                          set("material", "iron");
        	set("long", "它是一把天下少有的利器，只有真正的侠客，才配拥有这把宝剑。\n");
        	set("wield_msg","$N猛地拔出$n来，顺势在空中抖了个剑花。\n");
        	set("unwield_msg", "$N手中的$n突然在空中划了道长虹，真武剑随之插回剑鞘中。\n");
	}
    	init_sword(200);
	setup();
}

void destruct_me(object where, object me)
{
  message_vision("一道紫气闪过，$n被突如其来的霞光收走了！\n",where,me);
  destruct (me);
}

void init()
{
  object me = this_object();
  object where = environment();

  ::init();
  if (interactive(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}


