// snowsword perform
//by fly
//by tianlin 2001.7.1修改
#include <ansi.h>
#include <combat.h>
#include "/u/tianlin/eff_msg.h";
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int i, j, z;
        object weapon;
        j = me->query_skill("snowsword", 1);
        z = me->query_skill("baihua-zhang", 1);
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("「满天飞雪」只能在战斗中对对手使用。\n");
        if (!weapon || weapon->query("skill_type") != "sword"
             )
                return notify_fail("你必须在使用剑时才能使[满天飞雪」！\n");
        if(me->query_skill("snowsword", 1) < 120 )
                return notify_fail("你的风回雪舞剑法还不够娴熟，使不出「满天飞雪」绝技。\n");
        if(me->query_skill("baihua-zhang", 1) < 120 )
                return notify_fail("你的百花掌等级还不够娴熟，使不出「满天飞雪」绝技。\n");
        if(me->query_skill("unarmed", 1) < 120 )
                return notify_fail("你的掌法还不够娴熟，使不出「满天飞雪」绝技。\n");
        if( (int)me->query_skill("force") < 150 )
                return notify_fail("你的内功等级不够，使不出「满天飞雪」绝技。\n");
        if( (int)me->query_str() < 50)
                return notify_fail("你的膂力还不够强劲，使不出「满天飞雪」绝技。\n");
        if( (int)me->query("max_force") < 1500 )
                return notify_fail("你现在内力太弱，使不出「满天飞雪」。\n");      
        if( (int)me->query("force") < 500 )
                return notify_fail("你现在内力太弱，使不出「满天飞雪」。\n");      
//   if (!this_player()->query_temp("moon_tian")&&!wizardp(me))
//                            return notify_fail("没有西王母的指点，你自己领悟的了?..\n");
        msg = HIM "$N使出月宫不传之密「漫天飞雪」，身行顿时急若风回，轻灵似雪舞！\n" NOR;
        //me->add_temp("apply/strength", z);
      //  me->add_temp("apply/attack", (j+z)/5); 
        if(weapon->query("id") == "snowsword"){
     //     me->set_temp("moon_pfm", 1);
    //    me->add_temp("apply/dodge", 350);
         // me->add_temp("apply/damage", 350);
          msg = HIR"\n$N手中风回雪舞剑连划数剑，逼出道道金光，剑光中$N化身为二，掌剑齐出，直指$n！\n\n"NOR;
          }

  // if((string)me->query("id")=="tianlin") 
          {
     //     me->set_temp("moon_pfm_fly", 1);
     //     me->set_temp("moon_pfm", 1);
     //   me->add_temp("apply/dodge", 350);
  //        me->add_temp("apply/damage", 350);
        msg = HIM "\n\n$N使出逍遥山庄「漫天飞雪」，身行顿时急若风回，轻灵似雪舞,更胜月宫！" NOR;
          msg += HBBLU"\n$N更将风回雪舞剑法精华容于第一神功之中,$n早已心慌失乱！\n"NOR;
     //   me->add("force", 1000);
       }

        if(weapon->query("id") == "tianlin"){
    //      me->set_temp("moon_pfm", 1);
       // me->add_temp("apply/dodge", 350);
          //me->add_temp("apply/damage", 350);
          msg = HIR"\n$N手中紫青双剑一剑左手一剑右手，只见道道金光，剑光中$N化身为二，掌剑齐出，直指$n！\n\n"NOR;
          }
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
      //  if(me->query_temp("moon_pfm_fly"))
message_vision(HBGRN"\n$N潜运第一神功,内劲飘忽不定，打出一股阴阳内旋之力！"NOR,me);
//        weapon->unequip(); 
      //  me->delete_temp("weapon");
        me->reset_action();
        COMBAT_D->do_attack(me, target);
      //  if(me->query_temp("moon_pfm_fly"))
message_vision(HBYEL"\n$N潜运第一神功,身法忽呼飘渺,异常灵动,微风拂面,乱剑已至！"NOR,me);
//        weapon->wield();
        me->set_temp("weapon",weapon);
        me->reset_action();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
       // if(me->query_temp("moon_pfm_fly"))
message_vision(HBRED"\n$N潜运第一神功,内劲贯穿六脉,拳如钢铸，奔如速雷，行如电闪！"NOR,me);
//        weapon->unequip();
        me->delete_temp("weapon");
        me->reset_action();
        COMBAT_D->do_attack(me, target);
      //  if(me->query_temp("moon_pfm"))
                {
       // me->add_temp("apply/dodge", -350);
         // me->add_temp("apply/damage", -350);
        //if(me->query_temp("moon_pfm_fly"))
message_vision(HBMAG"\n$N潜运第一神功,身法忽呼飘渺,异常灵动,微风拂面,乱剑已至！"NOR,me);
                }
//        weapon->wield();
        me->set_temp("weapon",weapon);
        me->reset_action();
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
      //  me->delete_temp("moon_pfm");
        me->add("force", -100);
        //me->add_temp("apply/strength", -z);
      //  me->add_temp("apply/attack", -(j+z)/5);
        me->start_busy(1+random(3));

        return 1;
}
