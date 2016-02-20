//by tianlin 2001.7.30
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「"CYN"猪"YEL"耙"HIM"乱舞"NOR"」？\n");

        if(!me->is_fighting())
                return notify_fail("「"CYN"猪"YEL"耙"HIM"乱舞"NOR"」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

          if(me->query("family/family_name") != "天蓬帅府" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query_skill("skyriver-rake", 1) < 80)
                return notify_fail("你的天河钯法级别还不够，使不出这一招！\n");
       message_vision(CYN"\n$N的身形一变,突然使出开封城绝技<<<"CYN"猪"YEL"耙"HIM"乱舞"NOR+CYN">>>！\n"NOR,me,target);

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 3);
       message_vision(MAG"\n$N双手一抖，手中耙子坚硬无比，无坚不摧，伤害性甚为可怕。\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       
	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 4);
       message_vision(HIC"\n$N忽然，单手拿耙，横扫中路，一招"HIG"『横扫千军』"NOR+HIC"，真是威力无敌 !\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
       
	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 6);
       message_vision(HIW"\n$N双手高举耙子，从高空落下，伤害极大，真叫人后怕。\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 9);
       message_vision(HIY"\n$N看你动作不稳，趁机加强攻势，一招比一招厉害, 对方已经被攻的头昏眼胀。\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));       

	if (! present(target,environment(me))) return 1;
        me->set_temp("QJB_perform", 10);//一招比一招厉害.
       message_vision(HIM"\n$N大喝一声说道: "RED"呆子哪里跑"NOR+HIM" 吃俺老猪一耙再说。\n"NOR, me, weapon);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}

