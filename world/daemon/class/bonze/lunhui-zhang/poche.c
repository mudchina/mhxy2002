// laoniupoche.c 轮回杖法「老牛破车」式，为天下第一慢招
// by tianlin 2001.7.1,修改
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;
        string strr;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「老牛破车」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "staff")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("lunhui-zhang", 1) < 80 )
                return notify_fail("你的轮回杖法极不够娴熟，不会使用「老牛破车」这一招。\n");
          if((int)me->query("force") < 100 )
               return notify_fail("你的内力不足！\n");

        msg = HIY "$N使出轮回杖法的「老牛破车」一式，时间猛然一滞，周围一切都变慢了。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 )
        {
             attack_time=2+random((int)me->query_skill("lunhui-zhang",1)/30);
             if(attack_time>8)attack_time=8;
                me->add_temp("apply/attack",(int)me->query_skill("lunhui-zhang",1)/10);
                msg += CYN " 结果$p被$P的招式带的慢了下来！\n" NOR;
                message_vision(msg, me, target);
                msg = "$P趁机一连向$p发出"+chinese_number(attack_time)+"招\n";
                message_vision(msg, me, target);
                for(i = 0; i < attack_time; i++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0, "第"+chinese_number(i+1)+"杖。\n");
                me->add_temp("apply/attack",-(int)me->query_skill("lunhui-zhang",1)/10);

                me->start_busy(3);
                me->add("force", -100);
        }
        else
        {
                msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
                me->start_busy(2);
                message_vision(msg, me, target);
        }

        return 1;
}
