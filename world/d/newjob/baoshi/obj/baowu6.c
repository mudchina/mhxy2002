inherit ITEM;
#include <ansi.h>
inherit F_UNIQUE;
void create()
{
        set_name(YEL"混元金斗"NOR, ({"hunyuan dou","dou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此斗开天长出来，内藏天地按叁才\n");
                set("unit", "件");
                set("unique", 1);
                set("no_sell", 1);
                set("no_steal", 1);
                set("no_put",1);
                set("no_drop", 1);
                set("no_give", 1);
                set("is_monitored",1);        
        }
}


void init ()
{
  check_owner();
  add_action ("do_ji", "ji");
  if(userp(this_player())) 
     call_out("self_dest",600+random(600));
 
}
// 只见一道金光，把杨戬吸在里面
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
                
   if(item!="hunyuan dou"&&item!="dou") return notify_fail("你想对谁祭什么? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+huluname+"。\n");
    return notify_fail("你祭混元金斗失败。\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭混元金斗失败。\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "你想祭的人不在这里。\n");
            return notify_fail("你祭金蛟剪失败。\n");
    }
    
  message_vision (HIR"\$N"+HIY"口中念念有词,掏出混元金斗祭於空中！",me);

  if (hulu->query("interactive_usage") > (me->query("kar")/2))
  {
      message_vision (HIY"\n混元金斗在空中化做清烟随风散去了！\n"NOR,me);       
      destruct (hulu);  
      return 1; 
  }
  
 message_vision (HIY"\n只见混元金斗空中金光一闪\n"NOR,target,me);  
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = (int)me->query("daoxing");
        dp = target->query("daoxing");
        if( random(ap + dp) < dp ) success = 0;
        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
     
          message_vision (HIY"\n$N"+HIY"躲闪不急,被金光吸入斗中。\n"NOR,target,me);
          target->receive_damage("sen",me->query("mana_factor"));
          target->receive_damage("kee",me->query("mana_factor"));
          COMBAT_D->report_status(target);
          message_vision (HIG"\n$N"+HIG"往空中一指,混元金斗收回手中！\n",me,target);
          target->kill_ob(me);
          me->start_busy(1);
          target->start_busy(1);
       }else{
          message_vision(HIR"\n$N"+HIY"一闪身,躲过了这道金光\n"NOR,target,me);         
          message_vision (HIG"\n$N"+HIG"往空中一指,混元金斗收回手中！\n",me,target);
          target->kill_ob(me);
          me->start_busy(1);
      } 
  if (interactive(me)) hulu->add("interactive_usage",1);
  return 1;
}


void self_dest()
{
    object env=environment(this_object());
    if(env)
        tell_object(env, name()+HIY"突然混元金斗在化做一股清烟随风散去了！\n");
    destruct(this_object());
}
