//bazhinv.c by yushu 2001.1
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
                return notify_fail("你要对谁施展这一招「八稚女」？\n");

        if(!me->is_fighting())
                return notify_fail("「八稚女」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 250)
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("bashen",1) < 150)
                return notify_fail("你的八神流古武术级别还不够，无法使用「八稚女」!\n");

        weapon=me->query_temp("weapon");

        message_vision(HIR"\n$N大喊一声:接招!禁千二百十一式八稚女,直冲向$n!\n"NOR, me, target);
            message_vision(HIR"\n$N一式轻拳！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIC"\n$N又一式轻拳！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIB"\n$N一式前轻拳！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIM"\n$N一式梦弹！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIY"\n$N一式重拳！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIG"\n$N又一式重拳！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(WHT"\n$N顺手抓住了$n的脖子！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);
            message_vision(HIR"\n$N用自己的头砸向$n！\n"NOR, me, target);
        COMBAT_D->do_attack(me, target, weapon);

        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1);

        return 1;
}


