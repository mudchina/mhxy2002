//by tianlin 2001.7.30
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"HIY"「倒打一耙」"NOR"？\n");

        if(!me->is_fighting())
                return notify_fail(""HIY"「倒打一耙」"NOR"只能在战斗中使用！\n");

        if((int)me->query("max_force") < 800 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 900 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神太差，还想使用偷袭之招 ?\n");

          if(me->query("family/family_name") != "天蓬帅府" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");

        i=(int)me->query_skill("skyriver-rake",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("你的天河钯法还不够纯熟，还要多加练习才能使出绝招！\n");

  if (me->query_temp("fc_pfm_busy")) return notify_fail("绝招不能长使。\n");
        message_vision(HIC"\n$N装作逃跑,越跑越慢,霎时间突然回头,大喝一声: "HIR"呆!"NOR"\n\n"HIY"接着你使出了天河钯法中的"HIW"绝招"HIG"<<<"BLINK"倒打一耙"NOR+HIG">>>."NOR,me);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("QJB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100+random(100));
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

//        me->start_busy(2);
   me->set_temp("fc_pfm_busy",1);
   me->set_temp("no_move",1);
  call_out("remove_effect",1+random(3),me);
  call_out("remove_no_move",1,me);
        return 1;
}

void remove_effect(object me) {
  if (me)  me->delete_temp("fc_pfm_busy");
}
void remove_no_move(object me) {
  if (me) me->delete_temp("no_move");
}
