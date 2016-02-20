

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「清风抚面」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("xiaofeng-sword", 1) < 50 )
                return notify_fail("你的小风残月剑剑法不够娴熟，不会使用「清风抚面」。\n");
        if( (int)me->query("force") < 300 )
                return notify_fail("你现在内力太弱，不能使用「清风抚面」。\n");

        msg = CYN "$N手中的剑如风一般急速飞向了$n。\n"NOR;

        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
        {
                target->start_busy( (int)me->query_skill("xiaofeng-sword") / 20 +
 1);

                damage = damage +  2*(int)me->query_skill("xiaofeng-sword", 1);

                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -damage);
                msg += HIR"只见$N手中的剑转个不停,如同一张网罩向$n.\n$n顿时眼前一片金光，却发现自己的脸已被划成了烂柿子一般。\n"NOR;

                me->start_busy(2);
        } else
        {
                msg += CYN"可是$p猛地向边上一跃,跳出了$P的攻击范围。\n"NOR;
                me->add("force", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);

        if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}
