inherit ITEM;
inherit F_UNIQUE;
#include <ansi.h>
void create()
{
        set_name(HIG"定海珠"NOR, ({"dinghai zhu","zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此宝祭於空中，有五色毫光，纵然神仙，观之不明，应之不见。\n");
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
                
   if(item!="dinghai zhu"&&item!="zhu") return notify_fail("你想对谁祭什么? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+huluname+"。\n");
    return notify_fail("你祭定海珠失败。\n");
  }
if(uptime()-me->query_temp("last_ji") < 6) return notify_fail("你正忙着呢......\n");

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭定海珠失败。\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "你想祭的人不在这里。\n");
            return notify_fail("你祭定海珠失败。\n");
    }
    
  message_vision (HIG"\n只见$N"+HIG"掏定海珠朝空中一掷大喝一声: 看法宝！\n",me);

  
  
 msg = HIG"只见定海珠在空中回旋不断，发出五色毫光\n"NOR;
 message_vision(msg,me);
  
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = (int)me->query("daoxing")/1000;
        dp = (int)target->query("daoxing")/1000;
 if( random(ap) < dp/2 ) success = 0;

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
          
          message_vision (HIG"\n$N"+HIG"应声抬头往空中看去,刹时间五色毫光直刺双目,什么都看不清了。\n",target,me);
          target->start_busy(4+random(6));
          target->receive_damage("kee",me->query("mana_factor")/3);
          COMBAT_D->report_status(target);
           message_vision (HIG"\n$N"+HIG"伸手一指,定海珠又落回手中！\n",me,target);
          target->kill_ob(me);
          me->start_busy(1);
       }else{
    
          message_vision (HIG"\n$N"+HIG"充耳不闻,专心战斗！\n",target);
          message_vision (HIG"\n$N"+HIG"伸手一指,定海珠又落回手中！\n",me);
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
        tell_object(env, HIY"只见扑的一声,定海珠在你的怀里化为水珠不见了！。\n");
    destruct(this_object());
}
