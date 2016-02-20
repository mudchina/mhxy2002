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
                return notify_fail("你要对谁施展这一招「盘龙八式」？\n");
        if(!me->is_fighting())
                return notify_fail("「盘龙八式」只能在战斗中使用！\n");
       if((int)me->query("max_force") < 1200 )
                return notify_fail("你的内力不够！\n");
   if((int)me->query("force") < 1360 )
     return notify_fail("你的内力不足！\n");
     if((int)me->query("sen") < 600 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
      if((int)me->query_skill("qianjun-bang", 1) < 150)
                return notify_fail("你的千钧棒级别还不够，使用这一招会有困难！\n");
  if((string)me->query("family/family_name") != "方寸山三星洞" )
   return notify_fail("盘龙八式是方寸山三星洞的不传之秘，外人哪里能够领悟。\n");
        me->delete("env/brief_message");
   target->delete("env/brief_message");
message_vision(HIC"\n$N运足精神，身形一转使出灵台绝学"HIW"「盘龙八式」"NOR+HIC"霹雳间连续向$n攻出了八招！\n"NOR,me,target);
        me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("QJB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("QJB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
     me->receive_damage("sen", 360);
    me->add("force", -1000);
        if( !target->is_fighting(me) ) {

                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
       }
    me->start_busy(3+random(3));
        return 1;
}

