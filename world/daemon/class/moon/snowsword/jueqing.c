//绝情四剑.c by yushu 2001.2
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
            if(!target) target = offensive_target(me);
            if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「绝情四剑」？\n");

         if(!me->is_fighting())
                return notify_fail("「绝情四剑」只能在战斗中使用！\n");

        if(me->query("family/family_name")!="月宫")
                return notify_fail("不是月宫的不能用「绝情四剑」！\n");

/* if(me->query("moon/jueqing_perform")!=1)
                return notify_fail("你还没领会「绝情四剑」！\n");
*/
        if((int)me->query("max_force") < 500)
                     return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

         if((int)me->query("sen") < 250)
                return notify_fail("你的精神不足，没法子施用外功！\n");

         if((int)me->query_skill("snowsword",1) < 120)
                return notify_fail("你的风回雪舞剑法级别还不够，无法使用「绝情四剑」!\n");

        weapon=me->query_temp("weapon");
            message_vision(HIW"\n$N运足精神，抖手刺出一剑，"+weapon->query("name")+"化作四道光芒直射$n!\n"NOR, me, target);
            message_vision(HIR"\n$N一式「马嵬坡下泥土中，不见玉颜空死处」，脚踏「巽」位！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIG"\n$N一式「楼阁玲珑五云起，其中绰约多仙子」，占住「兑」位！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIC"\n$N一式「在天愿作比翼鸟，在地愿为连理枝」，连踏「乾」「坤」二位！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIB"\n$N一式「天长地久有时尽，此恨绵绵无绝期」，由「坤」向「乾」疾退！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
        me->receive_damage("sen", 100);
        me->add("force", -200);

            if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2+random(2));

        return 1;
}


