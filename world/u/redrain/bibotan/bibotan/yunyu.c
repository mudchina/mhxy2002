// update by swagger

#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        object weapon1;
        string weapon,msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("「翻云覆雨」只能在战斗中使用。\n");
        if( (int)me->query_skill("chuanyun-tui", 1) < 100 ||
           (int)me->query_skill("unarmed", 1) < 100 
                             )
                return notify_fail("你有的功夫还不够娴熟，不会使用「翻云覆雨」。\n");
        if(me->query_skill("force", 1) <100)
                return notify_fail("以你现在的内功修为还使不出「翻云覆雨」。\n");        
        if (me->query_skill_mapped("unarmed") != "chuanyun-tui")
                return notify_fail("你现在无法使用「翻云覆雨」进行攻击。\n");                                                                                 
        if( (int)me->query("max_force") < 1200 )
                return notify_fail("你的内力修为太弱，不能使用「翻云覆雨」！\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
msg = HIC "\n$N脸色一变，左脚点地，身体向后旋转，右腿随即「翻云覆雨」般扫向$n！\n" NOR;
msg += WHT "\n这一腿力度奇大!速度奇快!$n一愣之间，风声已经踢到了面前。"NOR;
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/2))
        {  
      target->start_busy(1);
if (random(me->query_skill("parry")) > random(target->query_skill("parry")/3*2))
                   {
        msg += HIC "\n$n招架不住这凌厉的一腿，被踢了个正着!\n" NOR;
                damage = (int)me->query_skill("chuanyun-tui", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage/2 + me->query("force_factor"),me);
                target->receive_wound("kee", damage/4,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "瘀伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
                me->start_busy(2);
                if(me->query_skill("chuanyun-tui", 1) > 129)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                    } else 
                {
        msg += HIB "\n没等$n反过神来，$N忽然身形急转，收右腿，抬左腿，
一前一后，一连二腿袭向$n，一腿快过一腿，连绵不尽！\n"NOR;
        message_vision(msg, me, target);
for (p=2;p<2+random(2);p++)
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
                if(random(me->query_skill("chuanyun-tui", 1))> 119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                         }
                 }
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIG"\n$n伏地一滚，狼狈不堪的躲开了。\n"NOR;
 if(me->query_skill("chuanyun-tui",1)>119)
                {
             remove_call_out("perform2");
                call_out("perform2", 0, me, target);    
                 }
        message_vision(msg, me, target);
        }
        return 1;
}

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,*limbs;
          if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("对手已经无力再战。\n");
        if( (int)me->query("force", 1) < 1000 )
                return notify_fail("$N又待出招，浑身却软弱无力，无法出招！\n");     
if (random(5)>2)
     msg = HIY "\n$N突然侧身，一个前空翻，右脚自上而下，足带风尘，照$n直劈下来！\n"NOR;
              {
      if (random(me->query("combat_exp")) > random(target->query("combat_exp")/3*2))
        {
       msg += MAG "\n$n眼睁睁的看着$N迎面一腿踢下，却无招架之力！\n" NOR;
                me->start_busy(2);
                target->start_busy(1);
                damage = (int)me->query_skill("unarmed", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage/2 + me->query("force_factor"),me);
                target->receive_wound("kee", damage/4,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
                me->start_busy(2);
        } else 
        {       
              me->start_busy(1+random(2));
                me->add("force", -200);                
                msg = WHT"$n一个反身,闪过$N凌厉的进攻。\n"NOR;
        message_vision(msg, me, target);
        }
              }
              return 1;
}