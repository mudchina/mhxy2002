#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(BLINK""HIG"绿宝石"NOR, ({"bao shi", "baoshi","shi"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_sell",1);
                set("unit","颗");
                set("color","g");  //绿
                set("no_put",1);
               // set("no_give",1);
                set("no_sell",1);
                set("long",HIG"一块发着闪闪绿光的宝石，传说是女娲补天石的碎块,也不知道什么时候落入凡间的。\n"NOR);
        }
        setup();
}

void init()
{
    
    add_action("do_enchase", "enchase");
    add_action("do_enchase", "inset");
}

int do_enchase(string arg)
{
   object in_obj;
   string item;
   string mats;
   string weapon_type;
   int rd,inset_num ;
   object me = this_player();
   object ob = this_object();
   
   if(!arg) return notify_fail("你要干什么？\n");
   if(sscanf(arg, "%s", item)!=1) return notify_fail("你要把宝石镶嵌到什么上？\n");
   if(!objectp(in_obj = present(item, me))) return notify_fail("你身上没有这样东西。\n");
   if( in_obj->query("equipped") )
      return notify_fail("你必须放下这样东西才能镶嵌宝石。\n");
   if( in_obj->query("no_zm")||in_obj->query_unique())
      return notify_fail("这件装备不能镶嵌宝石。\n");

   if(((int)me->query("potential")- (int)me->query("learned_points")) < 1000) notify_fail("潜能不足!\n");
   mats = in_obj->query("material");       //装备或武器
   inset_num = in_obj->query("inset_num");  // 嵌了几个了
   if(!inset_num) inset_num = 1;
   else inset_num = inset_num + 1;
   if(inset_num > 5) return notify_fail(in_obj->query("name")+"上已经镶嵌了太多的宝石了!\n");
   
   if(!in_obj->query("weapon_prop/damage"))   //防具
  {
       message_vision(CYN"$N把$n"+CYN"镶嵌到"+in_obj->query("name")+CYN"上 \n"NOR,me,ob);
       tell_room(environment(me),HIG"只见"+ob->name()+HIG"发出一团妖艳的绿光,环绕在"+in_obj->query("name")+HIG"的周围 \n"NOR);
       in_obj->add("armor_prop/spells",1 + random(10));
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加充满灵性了！\n"NOR,me);
//       me->add("bellicosity",1000);  
       me->add("potential", -1000);
       in_obj->set_weight(in_obj->query_weight()+1000);
       in_obj->set("no_sell",1);       
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_g",inset_num);  //装备g
       in_obj->set("name",HIG+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"上面嵌上了"HIW+chinese_number(inset_num)+"颗宝石\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
}else{  //武器
       message_vision(CYN"$N把$n"+CYN"镶嵌到"+in_obj->query("name")+CYN"上 \n"NOR,me,ob);
       tell_room(environment(me),HIG"只见"+ob->name()+HIG"发出一团妖艳的绿光,环绕在"+in_obj->query("name")+HIG"的周围 \n"NOR);
       
       message_vision(CYN""+in_obj->query("name")+CYN"似乎变得更加锋利了！\n"NOR,me);
       weapon_type = in_obj->query("skill_type");
       in_obj->add("weapon_prop/damage",1 + random(20));
       in_obj->add("rigidity",1 + random(20));       
       me->add("potential", -1000);
       in_obj->set_weight(in_obj->query_weight()+1000);
       in_obj->set("no_sell",1);       
       in_obj->set("inset_num",inset_num);
       in_obj->add("inset_g",inset_num);  //装备g
       in_obj->set("name",HIG+in_obj->query("name")+NOR);
       if(!in_obj->query("old_long")) in_obj->set("old_long",in_obj->query("long"));
       in_obj->set("long",in_obj->query("old_long")+"上面嵌上了"HIW+chinese_number(inset_num)+"颗宝石\n"NOR);
       in_obj->save();
       destruct(ob);
       return 1;
}


 
  return notify_fail("你镶嵌宝石失败了？\n");
}
