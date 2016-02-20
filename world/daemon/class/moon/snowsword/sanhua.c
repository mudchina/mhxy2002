// san.c  天女散花

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「天女散花」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
        if (((string)me->query("family/family_name") != "月宫")||(string)me->query("gender")!="女性")
                return notify_fail("咦？你是月宫仙女吗？\n");
        if( (int)me->query_skill("snowsword", 1) < 100 )
                return notify_fail("你的风回雪舞剑不够娴熟，不会使用。\n");
        
        if((int)me->query_skill("moonforce", 1) < 100 )
          
                return notify_fail("你的本门内功实在太差，没法用「天女散花」。\n");

        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你现在内力太弱，不能使用「天女散花」。\n");
        if(me->query_temp("san_busy"))
               return notify_fail("坏了，花散光了。。。\n");            
                        
        msg = CYN "$N凝神息气，手腕疾抖，挽出千万个剑花，铺天盖地飞向$n。\n"NOR;

//      if( !target->is_killing(me) ) target->kill_ob(me);

        if ((random(me->query("combat_exp"))>target->query("combat_exp")/2)||(random(me->query_skill("sword")) > target->query_skill("parry")/2 ))
        {
                target->start_busy(random(4)+1);
                
                damage = (int)me->query_skill("moonforce", 1);
                damage = damage +  (int)me->query_skill("snowsword", 1);
                damage = damage +  (int)me->query_skill("sword", 1)/2;
                
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);
                me->add("force", -200);
                msg += HIR"只见$N剑花聚为一线，穿向$n,\n$n只觉一股热流穿心而过，喉头一甜，鲜血狂喷而出！\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->report_status(target,1);
        } else 
        {
                msg += CYN"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
                me->add("force", -100);
                me->start_busy(random(4));
                message_vision(msg, me, target);
        }
        me->set_temp("san_busy",1);
        call_out("san_can",4+random(4),me);
        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
void san_can(object me) {
  if (!me) return;
  me->delete_temp("san_busy");
}
