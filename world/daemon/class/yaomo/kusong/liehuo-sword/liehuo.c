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
                return notify_fail("你要对谁施展这一招「烈火五剑招」？\n");

        if(!me->is_fighting())
                return notify_fail("「烈火五剑招」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 500 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("liehuo-sword", 70) < 70)
                return notify_fail("你的烈火剑法级别还不够，使用这一招会有困难！\n");
               
               if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("烈火五剑招必须配合火魔心法才能使用。\n");
          
              me->delete("env/brief_message");
            target->delete("env/brief_message");

message_vision(HIR"\n只见四周烈火重重,烈火化为五把利剑,直攻向$n！\n"NOR,me,target);

        me->set_temp("XFJ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("XFJ_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("XFJ_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("XFJ_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              
              me->set_temp("XFJ_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete_temp("XFJ_perform");

        me->receive_damage("sen", 100);
        me->add("force", -300);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}