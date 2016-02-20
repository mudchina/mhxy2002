#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int xiaohunqin,qin,ini_damage_apply,times,damage;
   string desc_msg="";
  int sword_level;
        
        xiaohunqin = (int)me->query_skill("xiaohunqin", 1);
        qin = (int)me->query_skill("qin", 1);
        
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「琴震四方」？\n");

        if(!me->is_fighting())
                return notify_fail("「琴震四方」只能在战斗中使用！\n");

        if(me->query("family/family_name") != "江湖浪子" )
                return notify_fail("你是哪儿偷学来的武功，也想用「"HIW"琴震四方"NOR"」?\n");

        if((int)me->query("max_force") < 3000 )
                return notify_fail("你的内力不够，无法施展「琴震四方」！\n");

        if((int)me->query("force") < 1500 )
		return notify_fail("你的内力不足，无法施展「琴震四方」！\n");

        if((int)me->query("sen") < 800 )
                return notify_fail("你的精神不足，无法施展「琴震四方」！\n");
        if( me->query("force_factor") > 0)
                return notify_fail("「琴震四方」绝技重招不重力。加力出招怎能琴走轻灵？\n");
        sword_level=(int)(xiaohunqin/50);
        if( xiaohunqin < 280)
                return notify_fail("你的销魂琴级别还不够，无法领悟到琴艺的真髓！\n");

        if((int)me->query_skill("wuji-force",1) < 250 )
                return notify_fail("你的无极心法级别还不够，无法领悟到琴艺的真髓！\n");
        if((int)me->query_skill("piaoxiang",1) < 250 )
                return notify_fail("你的血海飘香级别还不够，无法领悟到琴艺的真髓！\n");
        if((int)me->query_skill("lingxiyizhi",1) < 250 )
                return notify_fail("你的灵犀一指级别还不够，无法领悟到琴艺的真髓！\n");
        if (me->query_skill_mapped("force")!="wuji-force")
                return notify_fail("「琴震四方」必须配合无极心法才能使用。\n");
        
        if( qin < 280)
                return notify_fail("你对琴艺修为不够，无法使用这一招！\n");
        
                
        
        if( time()-(int)me->query_temp("wuxue_end") < 10 )
                return notify_fail("你过渡使用了内力，暂时无法施展「琴震四方」！\n");
   if ( sword_level <= 1 ) desc_msg = "" ; else
       desc_msg = chinese_number(sword_level);
  if ( sword_level > 9 ) desc_msg = "百";
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N销魂一笑，运聚手劲弹奏起了销魂琴，此时琴声凌震天下，势若雷霆，卷向$n。\n"NOR,me,target);
        damage=1;
        //前三剑
        message_vision(HIC"\n$N同时弹出销魂三曲，漫天琴声如虹攻向$n。\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",100);
        me->set_temp("WX_perform", 0);  
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        if (damage < 1) {me->add_temp("apply/damage",100);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 6);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //再两剑
        if( xiaohunqin > 349 && qin > 349 )
            {
            	message_vision(HIC"\n$N清啸一声琴以出手，威势强猛无涛,有若风雷并发,又使出了两招。\n"NOR,me);
                
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 7);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 8);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              }
      
           //最后两剑
           if( xiaohunqin > 400 && qin > 400 )
               {
               	    message_vision(HIC"\n$N冷喝一声,脚步前标,接过手中琴人闪电般攻向$n。\n"NOR,me,target);
               	    
               	    if (damage < 1) {me->add_temp("apply/damage",100);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 9);
                    damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      
                     if (damage < 1) {me->add_temp("apply/damage",300);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 10);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
                     	          }
	                
        me->delete_temp("WX_perform");
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->receive_damage("sen", 100);
        me->add("force", -1000);
        me->start_busy(3);
        me->set_temp("wuxue_end",time());
        return 1;
}

