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
              return notify_fail("你要对谁施展「孔雀开屏」？\n");

        if(!me->is_fighting())
              return notify_fail("「孔雀开屏」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 400 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("bainiao-jian", 1) < 50)
                return notify_fail("你的百鸟剑法级别还不够，使用这一招会有困难！\n");
        if((int)me->query_skill("ningxie-force", 1) < 50)
                return notify_fail("你的冰谷凝血功还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIW"$N弹剑清吟，身形闪动间，潇洒的向$n连攻四招！\n"NOR,me,target);

  me->set_temp("XFJ_perform", (1+random(9)));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
 me->set_temp("XFJ_perform", (2+random(8)));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

    me->set_temp("XFJ_perform", (3+random(7)));
     COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
    me->set_temp("XFJ_perform", (4+random(6)));
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("XFJ_perform");

   me->receive_damage("sen", 120);
    me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1+random(2));
        return 1;
}


