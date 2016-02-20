//By tianlin@mhxy for 2001.12.31

#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
                    set_name( HIY "梦幻西游大补丹" NOR , ({"da bu dan","dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
  set("unit", "颗");
       set("long", "经过巫师们九九八十一天精心炼制的大补丹(dan)，据说吃(eat)了有奇效。\n");
      set("value", 100);
    set("drug_type", "补品");
  }
  set("is_monitored",1);
  setup();
}

 int do_eat(string arg)
{
  object me = this_player();
       if (arg!="dan") return 0;
  if (me->query("newbie_liwu")) return notify_fail("你已经拿过礼物了，怎么还想要？\n");

seteuid(getuid());
  switch (random(5))
{
case 0:
{
     me->add("combat_exp",30000);
                   message_vision(HIM "$N拿起一颗梦幻西游大补丹，小心翼翼地吃了进去。
         好酷啊！$N的武学经验增加了30000点！\n" NOR, me);
break;
}
case 1:
{
       me->add("daoxing",20000);
       me->add("kill/nkgain",20000);
                     message_vision(HIG "$N拿起一颗梦幻西游大补丹，小心翼翼地吃了进去。
           好酷啊！$N的道行增加了20年！\n" NOR, me);
break;
}
case 2:
{
        me->add("potential",50000);
                      message_vision(HIR "$N拿起一颗梦幻西游大补丹，小心翼翼地吃了进去。
            好酷啊！$N的潜能增加了50000点！\n" NOR, me);
break;
}
case 3:
{
        me->add("force",300);
        me->add("maximum_force",300);
        me->add("max_force",300);
                        message_vision(HIB "$N拿起一颗梦幻西游大补丹，小心翼翼地吃了进去。
             好酷啊！$N的内力增加了300点！\n" NOR, me);
break;
}
case 4:
{
        me->add("mana",300);
        me->add("max_mana",300);
        me->add("maximum_mana",300);
                        message_vision(HIW "$N拿起一颗梦幻西游大补丹，小心翼翼地吃了进去。
             好酷啊！$N的法力增加了300点！\n" NOR, me);
break;
}
}
  me->set("newbie_liwu",1);
  destruct(this_object());
  return 1;
}
