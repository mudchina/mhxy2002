//by tianlin 2001.7.1修改

#include <ansi.h>
inherit SSERVER;
#include "/u/tianlin/eff_msg.h";

int perform(object me, object target)
{       
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail(""HIR"「"NOR+CYN"摩云"NOR+YEL"绝杀"NOR+HIR"」"NOR"只能在战斗中使用。\n");
        if( (int)me->query_skill("moyun-shou", 1) < 100 ||
           (int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("你有的功夫还不够娴熟，不会使用"HIR"「"NOR+CYN"摩云"NOR+YEL"绝杀"NOR+HIR"」"NOR"。\n");
/*
        if((int)me->query_skill("huomoforce", 1) <120)
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+CYN"摩云"NOR+YEL"绝杀"NOR+HIR"」"NOR"。\n");
*/
        if(me->query("family/family_name") != "火云洞" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");
        if((int)me->query_skill("force", 1) <100)
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+CYN"摩云"NOR+YEL"绝杀"NOR+HIR"」"NOR"。\n");
        if (me->query_skill_mapped("unarmed") != "moyun-shou")
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+CYN"摩云"NOR+YEL"绝杀"NOR+HIR"」"NOR"。\n");
        if( (int)me->query("max_force") < 1200 )
return notify_fail("以你现在的内功修为还使不出"HIR"「"NOR+CYN"摩云"NOR+YEL"绝杀"NOR+HIR"」"NOR"。\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("你的真气不够！\n");
       msg = YEL "\n\n$N突然临空腾起,“嗡”的一声，一掌凌空击向$n的胸口！！\n" NOR;
if (me->query("combat_exp") > target->query("combat_exp")/4)
        {
                me->start_busy(1);
                target->start_busy(2);
                damage = (int)me->query_skill("moyun-shou", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("moyun-shou", 1) > 119)
               target->set_temp("last_damage_from", me);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIY"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

// 第二击

int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
        msg = MAG "\n但见$N突然一个仰身,斜斜扑地,募的绕身回劈,$n眼前一阵花影!!\n" NOR;
        message_vision(msg, me, target); 
if (me->query("combat_exp") > target->query("combat_exp")/4)
        {
       msg = CYN "$N左手一收一放,反手之间,就是一掌!!!\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("moyun-shou", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage*3/2);
                target->receive_damage("kee", damage,me);
                target->receive_wound("kee", damage/2,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("moyun-shou", 1) > 180)
             remove_call_out("perform3");
                call_out("perform3", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIY"可是$p突然袭击，料敌之先,非但躲开对手攻击,$N反而搞了个手忙脚乱。\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

//第三击

int perform3(object me, object target)
{
        string msg,weapon;
        int p,extra,j;
       j=2+random(3);
    extra = (int)me->query_skill("moyun-shou");
    weapon = me->query_temp("weapon");  
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你鄙视地一笑,缓缓收回漫天的内力，傲然而立!!\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("你待要再出第三击，却发现自己的内力不够了！\n");     
    msg = HIR
"\n$N双手按地一撑而起,几步之间,已然站在$n面前,
$n只见满天红霞,裹住$n全身,$N狂风暴雨般连出数招!!\n"NOR;
message_vision(msg, me, target);
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/dodge", extra);
        me->add_temp("apply/parry", extra);
for (p=1;p<2+random(2);p++)
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        if( !target->is_fighting(me) ) 
                if( living(target) ) 
                        if( userp(target) ) target->fight_ob(me);
    msg = YEL
"\n\n$N鄙视地一笑,缓缓收回漫天的内力，傲然而立!!\n"NOR;
message_vision(msg, me, target);
    msg = YEL
"满天的内力缓缓撤消,$n顿时一轻,压力消缓!!\n"NOR;
message_vision(msg, me, target);
        me->add_temp("apply/parry", -extra);
        me->add_temp("apply/dodge", -extra);
        me->add_temp("apply/attack",-extra);
        me->start_busy(1+random(1));
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/4))
    {                if(me->query_skill("moyun-shou", 1) > 200)
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
     }
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 3000 )
                return notify_fail("你待要再出第四击，却发现自己的内力不够了！\n");     
        msg = HBYEL "\n那里料到在$N撤回内力之际,$N双手一拱，尤有内力发出一击\n" NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/2))
        {
       msg = CYN "$n慌乱中已经躲闪不及,$N得理不侥人,抢前就是一拳\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("moyun-shou", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage*3/2);
                target->receive_damage("kee", damage*2,me);
                target->receive_wound("kee", damage,me);               
                me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "内伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        } else 
        {       me->start_busy(3);
                me->add("force", -200);                
                msg += HIY"可是$p突然袭击，料敌之先,非但躲开对手攻击,$N反而搞了个手忙脚乱。\n"NOR;
        message_vision(msg, me, target);
        }
        return 1;
}
