//xfcylqn.c by greenwc

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
               return notify_fail("你要对谁施展这一招「晓风残月冷泉凝」？\n");

       if(!me->is_fighting())
               return notify_fail("「晓风残月冷泉凝」只能在战斗中使用！\n");

if((int)me->query("force") < 500 )
	return notify_fail("你的内力不足！\n");

  if((int)me->query("sen") < 200 )
            return notify_fail("你的精神不足，没法子施用外功！\n");
      if((int)me->query_skill("xiaofeng-sword", 1) < 100)
            return notify_fail("你的晓风残月剑还不够纯熟，难以体会高深的御剑技巧！\n");

      me->delete("env/brief_message");
target->delete("env/brief_message");

message_vision(HIC"\n$N姿势优美的一个转身，手中剑已经不在，$n只看到了——\n"NOR,me,target);

me->set_temp("XXX_perform", 9);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->set_temp("XXX_perform", 10);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->receive_damage("sen", 20);
me->add("force", -70);
me->start_busy(1+random(2));

 if((int)me->query_skill("moonforce", 1) > 119)
{
         me->set_temp("XXX_perform", 11);  
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

         me->set_temp("XXX_perform", 12);  
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

me->receive_damage("sen", 30);
me->add("force", -80);
me->start_busy(1+random(2));
}

     me->delete_temp("XXX_perform");

       if( !target->is_fighting(me) ) {
              if( living(target) ) {
                     if( userp(target) ) target->fight_ob(me);
                     else target->kill_ob(me);
}
}

  return 1+random(2);
}
