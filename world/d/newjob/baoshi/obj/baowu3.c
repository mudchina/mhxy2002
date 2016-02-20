inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
        set_name(HIR"火龙镖"NOR, ({"huolong biao","biao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "只见长有七寸五分，放出华光，火焰夺目，名曰：“心钉。”\n");
                set("unit", "件");
                set("unique", 1);
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_put",1);
                set("no_drop", 1);
                set("no_give", 1);
                set("is_monitored",1);
                set("baowu",1);

        }
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
                
   if(item!="biao"&&item!="huolong biao") return notify_fail("你想对谁祭什么? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+huluname+"。\n");
    return notify_fail("你祭火龙镖失败。\n");
  }
if(uptime()-me->query_temp("last_ji") < 6) return notify_fail("你正忙着呢......\n");

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭火龙镖失败。\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "你想祭的人不在这里。\n");
            return notify_fail("你祭火龙镖失败。\n");
    }
    
   message_vision (HIR"\n只见$N"+HIR"冷不防掏出火龙镖回手一掷！",me);

  
       message_vision (HIR"\n只见火龙镖在空中华光顿现，火焰夺目,直向$N"+HIR"当胸打去\n"NOR,target,me);  
       me->add("mana", -400);
       me->receive_damage("sen", 30);    
       success = 1;

        ap = (int)me->query("daoxing")/1000;
        dp = target->query("daoxing")/1000;
 if( random(ap+dp) < dp/4 ) success = 0;
 
     

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
     
          message_vision (HIR"\n$N"+HIR"躲闪不急,大叫一声火龙镖透胸而出。\n"NOR,target,me);
          target->receive_damage("sen",100+me->query("mana_factor"));
          COMBAT_D->report_status(target);
          message_vision (HIR"\n火龙镖一个回旋,落回到$N"+HIR"的手中\n"NOR,me,target);
          target->kill_ob(me);
          me->start_busy(1);
          target->start_busy(1);
       }else{
          message_vision(HIR"\n$N"+HIR"一转身,闪过了$n"+HIR"这一击,不禁心中惊出一身冷汗！\n"NOR,target,me);         
          message_vision (HIR"\n火龙镖一个回旋,落回到$N"+HIR"的手中\n"NOR,me,target);
          target->kill_ob(me);
          me->start_busy(1);
      
      } 
   me->set_temp("last_ji",uptime());
  if (interactive(me)) hulu->add("interactive_usage",1);
  return 1;
}

void self_dest()
{
    object env=environment(this_object());
    if(env)
        tell_object(env, HIY"只见啪的一声,火龙镖腾空而起在空中炸了个粉碎！。\n");
    destruct(this_object());
}
