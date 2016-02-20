// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// hengha.c
#include <ansi.h>

inherit SSERVER;

void end_cast(object me,object target);
void cast_person(object me,object target);

int cast(object me, object target)
{
        string msg;
        int howlong;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施法？\n");

	if((int)me->query_skill("bihai-spells") < 160)
            return notify_fail("就你个小样还想翻江倒海！\n");
	if( me->query_temp("cast_daohai"))
	        return notify_fail("你已经在施法中了！\n");        

        if((int)me->query("mana") < 2000 )
                return notify_fail("你的法力不够！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -1000);
        me->receive_damage("sen", 100);
        if( random(me->query("max_mana")) < 600 ) {
                write("不好！没翻起来！\n");
                return 1;
        }
        
	msg = HIC
	"\n$N口中念了句咒文，双手朝天，大喝一声：漫漫的江水啊，广阔的大海啊，请助我除敌！
\n只见周围数道白光闪过，$N已经消失不见了。!\n"NOR;
	message_vision(msg,me,target);
	me->set("env/invisibility", 1);
	howlong=me->query_skill("bihai-spells")/6;
	if(howlong>40)howlong=40;
	me->set_temp("cast_daohai",1);
    cast_person(me,target);
	call_out("end_cast",howlong,me,target);
    environment(me)->set("oldlong",environment(me)->query("long"));
  environment(me)->set("long", environment(me)->query("oldlong")+"\n周围变成了一片汪洋大海......\n\n");
	
       if( !target->is_fighting(me) ) {
       if( living(target) ) {
             if( userp(target) ) target->fight_ob(me);
             else
		target->kill_ob(me);
             }
                me->kill_ob(target);
        }

	
        me->start_busy(1);
        return 3+random(5);
}

void cast_person(object me,object target)
{
  int ap,dp,damage;
  string msg;

  if(!target||environment(target) != environment(me)||!me->is_fighting(target)){
  	remove_call_out("cast_person");
  	remove_call_out("end_cast");
  	end_cast(me,target);
  	return;
  }
if (target)     target->delete_temp("no_move");
  if(random(2)){
    msg = HIC
         "\n江水翻腾，$N双手一措，一片江水化为一道水剑，一闪间疾刺向$n！\n"NOR;
    ap = me->query_skill("spells");
    ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
    ap += (int)me->query("combat_exp");
    dp = target->query("combat_exp");
    if( random(ap + dp) > dp ) {
       damage = (int)me->query("max_mana") / 10 +
           random((int)me->query("eff_sen") / 5);
       damage -= (int)target->query("max_mana") / 10 +
           random((int)target->query("eff_sen") / 5);                   
       damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
       if( damage > 0 ) {
           msg +=  HIR "\n结果「嗤」地一声，水箭从$n身上透体而过！！\n" NOR;
          target->set_temp("no_move",1);
           damage +=random((damage*(int)me->query_skill("spells"))/200);
                        target->receive_damage("kee", damage/2, me);
                        target->receive_wound("kee", damage/6, me);
         }else msg += "\n结果「嗤」地一声，水箭无声无息地钻入地下，没起作用。\n";
    }else msg += "\n结果水箭无声无息地钻入地下，没起作用。\n";     
    message_vision(msg, me, target);
  }else {
     msg = HIC
     "\n半空中大海咆哮，$N从海水中升起，双手持叉，借着水的力量向$n迎面刺来！\n" NOR;

     ap = me->query_skill("spells");
     ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
     ap += (int)me->query("combat_exp");
     dp = target->query("combat_exp");
     if( random(ap + dp) > dp ) {
         damage = (int)me->query("max_mana") / 10 +
            random((int)me->query("eff_sen") / 5);
         damage -= (int)target->query("max_mana") / 10 +
	    random((int)target->query("eff_sen") / 5);                   
         damage+=(int)me->query("mana_factor")-random((int)target->query("mana_factor"));
         if( damage > 0 ) {
            msg +=  HIR "\n$n一个不留神，被刺的血流满面！\n" NOR;
             target->set_temp("no_move",1);
             damage +=random((damage*(int)me->query_skill("spells"))/200);
            target->receive_damage("kee", damage/2, me);
            target->receive_wound("kee", damage/6, me);
          }else msg += "\n但是被$n躲开了。\n";
      }
      else msg += "\n但是被$n躲开了。\n";
      message_vision(msg, me, target);
  }
  call_out("cast_person",5,me,target);    	
}

void end_cast(object me,object target)
{
    string msg;
    	
    msg = HIC
     "\n水慢慢的散去了，露出了$N的身影。\n" NOR;
    message_vision(msg,me);
    me->set("env/invisibility", 0);
if (target)     target->delete_temp("no_move");
    if(environment(me)->query("oldlong"))
       environment(me)->set("long",environment(me)->query("oldlong"));
    me->delete_temp("cast_daohai");
    remove_call_out("cast_person");	
}
