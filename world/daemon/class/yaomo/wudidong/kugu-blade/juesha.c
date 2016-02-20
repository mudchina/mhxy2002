//focus 2001.5.1
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
                return notify_fail("「枯骨绝杀」只能在战斗中使用。\n");
       
        if(me->query("family/family_name")!="陷空山无底洞")
            return notify_fail("“枯骨绝杀”只有无底洞门人才可以用！\n");

        if( (int)me->query_skill("kugu-blade", 1) < 160 ||
           (int)me->query_skill("blade", 1) < 160 )
                return notify_fail("你有的功夫还不够娴熟，不会使用「枯骨绝杀」。\n");
        if((int)me->query_skill("dodge", 1) <160)
            return notify_fail("以你现在的轻功修为还使不出「枯骨绝杀」。\n");
        if((int)me->query_skill("force", 1) <160)
            return notify_fail("以你现在的内功修为还使不出「枯骨绝杀」。\n");
        if( (int)me->query("max_force") < 1200 )
            return notify_fail("以你现在的内功修为还使不出「枯骨绝杀」。\n");
        if( (int)me->query("force") < 1600 )
            return notify_fail("你的内力不够！\n");
       msg = HIM"\n$N突然临空腾起, 刀光一闪，已挥向$n的胸口！！\n" NOR;
if (random(me->query("combat_exp")) > target->query("combat_exp")/5)
        {
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("kugu-blade", 1);
                damage = damage + random(damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);               
                me->add("force", -200);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "割伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("kugu-blade", 1) > 160)
                {
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                         }
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg += HIG"可是$p伏地一滚，躲开了对手的攻击。\n"NOR;
                if(me->query_skill("kugu-blade", 1) > 180)
                {
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                 }
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
        if( (int)me->query("force", 1) < 1000 )
                return notify_fail("你待要再出第二击，却发现自己的内力不够了！\n");     
if (random(5)>2)
        msg = HIC"\n但见$N突然一个仰身,斜斜扑地,募的绕身回劈,$n眼前一阵花影!!\n"NOR;
else 
        msg = HIG"\n但见$N突然一个仰身,斜斜扑地,募的绕身回劈,$n眼前一阵花影!!\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
        {
       msg = CYN "漫天光影中，一刀自空中杀来.....!!!\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("blade", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);               
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "割伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("force", 1) > 180)
                {
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
                 }
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg = WHT"可是$p料敌之先,抢攻几招，反逼$N连连后退。\n"NOR;
                if(me->query_skill("force", 1) > 200)
                {
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
                 }
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
    extra = (int)me->query_skill("dodge");
    weapon = me->query_temp("weapon");  
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你鄙视地一笑,缓缓收回漫天的刀光，傲然而立!!\n");
        if( (int)me->query("force", 1) < 800 )
                return notify_fail("你待要再出第三击，却发现自己的内力不够了！\n");     
    msg = HIR
"\n$N按刀点地一撑而起,几步之间,已然站在$n面前,
$n只见满天红霞,裹住$n全身,$N狂风暴雨般连出数招!!\n"NOR;
message_vision(msg, me, target);
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/dodge", extra);
        me->add_temp("apply/parry", extra);
for (p=1;p<2+random(4);p++)
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        if( !target->is_fighting(me) ) 
                if( living(target) ) 
                        if( userp(target) ) target->fight_ob(me);
        me->add("force", 400);
    msg = YEL
"\n\n$N鄙视地一笑,缓缓收回漫天的刀光，傲然而立!!\n"NOR;
message_vision(msg, me, target);
    msg = YEL
"满天的刀光缓缓撤消,$n顿时一轻,压力消缓!!\n"NOR;
message_vision(msg, me, target);
        me->add_temp("apply/parry", -extra);
        me->add_temp("apply/dodge", -extra);
        me->add_temp("apply/attack",-extra);
        me->start_busy(1+random(2));
/*
if (random(me->query("combat_exp")) > random(target->query("combat_exp")/4))
    {                if(me->query_skill("fly-king", 1) > 200)
             remove_call_out("perform4");
                call_out("perform4", 1, me, target);    
     }
*/
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
        if( (int)me->query("force", 1) < 1000 )
                return notify_fail("你待要再出第四击，却发现自己的内力不够了！\n");     
if (random(5)>2)
        msg = YEL"\n那里料到在$N回刀之际,$N单手一送，又挥向$n\n"NOR;
else 
        msg = RED"\n\n那里料到在$N回刀之际,$N单手一送，又挥向$n\n"NOR;
        message_vision(msg, me, target); 
if (random(me->query("combat_exp")) > random(target->query("combat_exp")*3))
        {
       msg = CYN "$n慌乱中已经躲闪不及,$N得理不侥人,抢前就是一刀\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("force", 1);
                damage = damage+(int)me->query_skill("force", 1);
                damage = damage + random(damage/2);
                target->receive_damage("kee", damage*2);
                target->receive_wound("kee", damage);               
                me->add("force", -300);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "刺伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target);
if (me->query_skill("spells", 1) > 200 && random(10)>3)
                {
if (random(5)>2)
       
    msg = BLU"$N按刀点地一撑而起,几步之间,已然站在$n面前,$N暗地潜运内力!!\n"NOR;
else 
    msg = "$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开。\n";
       
                   message_vision(msg, me, target);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                 }
             else {
                   msg = YEL"\n\n$N鄙视地一笑,缓缓收回漫天的刀光，傲然而立!!\n"NOR;
                   msg += YEL"满天的刀光缓缓撤消,$n顿时一轻,压力消缓!!\n"NOR;
                   message_vision(msg, me, target);
                  }
        } else 
        {       me->start_busy(2);
                me->add("force", -200);                
                msg = HIC"可是$p一个反身,轻轻躲过$N凌厉的进攻。\n"NOR;
        message_vision(msg, me, target);
if (me->query_skill("yaofa", 1) > 200 && random(10)>6)
                {
if (random(5)>2)
         msg = HIB"$N右手伸出，在$n手腕上迅速无比的一按，顺势跳到一旁。\n"NOR;
else 
    msg = "$n只觉眼前一花，似乎见到$N身形一幌，但随即又见$N回到原地，却似从未离开。\n";
                   message_vision(msg, me, target);
             remove_call_out("perform2");
                call_out("perform2", 1, me, target);    
                 }
             else {

             remove_call_out("perform3");
                call_out("perform3", 1, me, target);    
                  }
        }
                me->add("force", 400);                
        return 1;
}
