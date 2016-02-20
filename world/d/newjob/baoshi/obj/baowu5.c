inherit F_UNIQUE;
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"金蛟剪"NOR, ({"jinjiao jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此剪乃是两条蛟龙，采天地灵气，受日月精华，起在空中，往来上下，\n祥云护体，头并头如剪，尾交尾如股；不怕你得道神仙，一插两段。\n");
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
                
   if(item!="jinjiao jian"&&item!="jian") return notify_fail("你想对谁祭什么? \n");
   
   if ((int)me->query("mana") < 500)
  {
    tell_object (me, "你的法力不足，祭不了"+huluname+"。\n");
    return notify_fail("你祭金蛟剪失败。\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭金蛟剪失败。\n");
  }
 
  if(!objectp(target = present(ji_ob, environment(me))) || !living(target))
    {
            tell_object (me, "你想祭的人不在这里。\n");
            return notify_fail("你祭金蛟剪失败。\n");
    }
if(uptime()-me->query_temp("last_ji") < 6) return notify_fail("你正忙着呢......\n");
    
  message_vision (HIR"\n$N"+HIY"掏出金蛟剪往空中一掷！",me);

  
 message_vision (HIY"\n只见金蛟剪在空中化做两条金蛟向$N"+HIY"扑去\n"NOR,target,me);  
 me->add("mana", -400);
 me->receive_damage("sen", 30);    
 success = 1;
        ap = (int)me->query("daoxing");
        dp = target->query("daoxing");
       if( random(ap) < dp ) success = 0;
 
     

        ap = (int)me->query("mana");
        dp = (int)target->query("mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compare current mana. this is important. you need recover to try again.
      if(success == 1 ){
     
          message_vision (HIY"\n$N"+HIY"躲闪不急,两条金蛟拦腰截来,差点被剪为两段。\n"NOR,target,me);
          target->receive_damage("sen",me->query("mana_factor"));
          target->receive_damage("kee",me->query("mana_factor"));
          COMBAT_D->report_status(target);
          message_vision (HIY"\n金蛟一个盘旋,又化为金剪落回到$N"+HIY"的手中\n"NOR,me,target);
          target->kill_ob(me);
          me->start_busy(1);
          target->start_busy(1);
       }else{
          message_vision(HIR"\n$N"+HIY"一闪身,闪过了金蛟这致命的一击\n"NOR,target,me);         
          message_vision (HIY"\n金蛟一个盘旋,又化为金剪落回到$N"+HIR"的手中\n"NOR,me,target);
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
        tell_object(env, name()+HIY"突然金蛟剪腾空而起,化做两条蛟龙穿云而去！。\n");
    destruct(this_object());
}
