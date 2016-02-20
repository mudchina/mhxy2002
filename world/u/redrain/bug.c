//礼物
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"举报奖"NOR, ({"bug gift","gift"}));
    set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "件");
        set("long",
              HIR+"                ┌──────────────────────┐
                │               "HIW""BLINK"举报臭虫有功"NOR"         "HIR"        │ 
                └──────────────────────┘"NOR"
流氓巫师红雨给你的奖励，请打开(chai)来看看是什么？
"NOR
);
    set("value", 2000);
    set("no_sell",1);
    set("no_get",1);
    set("no_put",1);
    set("no_drop",1);
  }
    setup();
}
void init()
{
    add_action("do_chai", "chai");
}
int do_chai(string arg)
{
    string *skills ,str;
    mapping all_skills;
    object me = this_player();
    int i;
  if (!id(arg))  return notify_fail("你要拆什么？\n");

 {

 {
{
 str="听说"+me->name()+"举报bug有功，得到了红雨的奖励！"NOR;
 message("channel:rumor",HIM"【臭虫精灵】某人："+str+"\n"NOR,users());
}      me->add("max_force", 100);
       me->add("max_mana",100);
       me->add("maximum_force", 100);
       me->add("maximum_mana",100);
       me->add("potential",50000);
       me->add("combat_exp",20000) ;
       me->add("daoxing",20000);
     } 
 tell_object(me,HIC "你增加了100点内力，100点法力，5万潜能，2万武学，20年道行。\n" NOR);
  }  destruct(this_object());
     return 1;
}
void owner_is_killed() { destruct(this_object()); }


