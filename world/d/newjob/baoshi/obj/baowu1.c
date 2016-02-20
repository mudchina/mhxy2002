inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>

void create()
{
        set_name(HIM"八卦云光帕"NOR, ({"yunguang po", "po"}));
        set_weight(80);
        set("long", "有坎离震兑之宝，包罗万象之珍\n");
        set("unit", "件");
        set("unique", 1);
        set("no_sell", 1);
        set("no_steal", 1);
        set("no_put",1);
        set("no_drop", 1);
        set("no_give", 1);
        set("is_monitored",1);
        set("baowu",1);
        setup();
}
void init ()
{
  check_owner();
  add_action ("do_ji", "ji");
if(userp(this_player())) 
     call_out("self_dest",7200+random(600));
}

int do_ji (string arg)
{
  string msg,ji_ob,item;
  int ap, dp,success;
  object target;
  object hulu = this_object ();
  object me = this_player();
  string huluname = hulu->query("name");
  object victim;

   if( sscanf(arg, "%s on %s", item, ji_ob)!=2 ) return notify_fail("你想对谁祭什么？\n");
                
   if(item!="po"&&item!="yunguang po") return notify_fail("你想对谁祭什么? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+huluname+"。\n");
    return notify_fail("你祭八卦云光帕失败。\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭八卦云光帕失败。\n");
  }
 
  
  message_vision (HIY"\n$N口中念着咒语，掏出八卦云光帕往空中一掷，：黄巾力士何在！",me);

  
  if(!objectp(target = find_living(ji_ob))||!environment(target)){
            tell_room(environment(me),"\n半空中现出一朵金色云彩，一个黄巾力士拱手行礼：禀法主，找不到这个人！\n"NOR);
            return 1;
    }
 msg = HIY"速去将"+target->query("name")+"抓来！\n半空中现出一朵金色云彩，一个浑身金甲的黄巾力士现出身形：是！然后就风驰电掣般地去了。\n"NOR;
 message_vision(msg,me);
  
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = me->query_skill("spells");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
 
        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared max_mana.

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
          tell_room(environment(target),HIY"突然空中金色云彩陡现,一位黄巾力士平空将"+target->query("name")+"拿去了。\n"NOR);       
          target->move(environment(me));
          msg =  HIY "不一会儿，金色云彩陡现，黄巾力士将$n往地上一扔，把$n摔了个头晕脑胀\n" NOR;
          message_vision(msg,me,target);
          me->kill_ob(target);
          target->kill_ob(me);
          target->start_busy(1+random(5));
       }else{
      msg =  HIY "不一会儿，半空传来黄巾力士大叫：望法主赎罪，抓不到"+target->query("name")+"！\n" NOR;
           message_vision(msg,me);         
           me->start_busy(2);
      
      } 
  if (interactive(me)) hulu->add("interactive_usage",1);
  return 1;
}

void self_dest()
{
    object env=environment(this_object());
    if(env)
        tell_object(env, HIY"只见呼的一声,八卦云光帕随风飘走了！\n");
    destruct(this_object());
}
