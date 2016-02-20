#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
        string msg;
        int success, ap, dp, howlong;
   int dayphase;

   dayphase =NATURE_D->query_current_day_phase();

//        if(!me->is_fighting())
//        return notify_fail("寒封术只可以在战斗中施展！\n");
        if( !target ) target = offensive_target(me);
   if((int)me->query_skill("spells") < 100 || (int)me->query_skill("fumozhou",1) < 60)
     return notify_fail("你还没学会寒封术……\n");

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这个法术？\n");

   if( !living(target) )
                return notify_fail("人都晕了你还要冻人家？\n");
        if(target->query_temp("no_move") )
        return notify_fail("有必要吗？"+target->query("name")+"已经不能动了。\n");

        if((int)me->query("mana") < 400 )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 50 )
                return notify_fail("你的精神没有办法有效集中！\n");

        me->add("mana", -400);
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 30 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIW "$N双手一聚，形成一团奇冷的寒气，向$n射来！\n\n" ;

   success = 1;
   ap = me->query_skill("fumozhou");
   ap = ap * ap * ap /12 ;
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");
   if (dayphase < 6){
   if( random(ap + dp) < dp ) success = 0;
   } 
   else if( random(ap + dp) < dp / 2) success = 0;

   ap = (int)me->query("max_mana");
   dp = (int)target->query("max_mana");
   if (dayphase < 6){
   if( random(ap + dp) < dp*2/3 ) success = 0;
   } 
   else if( random(ap + dp) < dp / 2) success = 0;

   ap = (int)me->query("mana");
   dp = (int)target->query("mana");
   if (dayphase < 6){
   if( random(ap + dp) < dp ) success = 0;
   } 
   else if( random(ap + dp) < dp * 2 / 3) success = 0;

   howlong = 0;        
   if(success == 1 ){
     msg +=  HIW "奇冷的寒气包围了$n的全身，将$n凝聚成冰块！\n" NOR;
      target->set_temp("frozen",1);
   if( target->is_die() ) return 1;

     target->set_temp("no_move", 1); 
 
     howlong = (me->query_skill("spells") / 10)+1;
     if(howlong>60) howlong=60;
   }       
   else {
     msg +=  HIR "$n满脸不屑，挥挥手便将寒气挥散了！\n" NOR;   
   } 

        message_vision(msg+NOR, me, target);

   if( living(target) ) target->kill_ob(me);

if (success == 0) {
return 1+random(2);
}

   if( howlong>0 ) call_out("remove_frozen", howlong, target);
        
   return 3+random(5);
}


void remove_frozen(object target)
{ 
   if( !target ) return;
   if( !living(target) ){
    call_out("remove_frozen", 1, target);
    return;
   }   if(target) target->delete_temp("no_move");      
   message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n" NOR, target);
   if(target) target->delete_temp("frozen");
   return;
}

