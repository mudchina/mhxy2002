//link 2001.2.20
 
#include <ansi.h>
 
inherit SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        object ob;
        int skill, skill2, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("umbrella");
        skill2 = me->query_skill("force");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "umbrella")
                        return notify_fail("有没搞错，没伞怎么能使「裂石穿金」？\n");
        if( !me->is_fighting()|| !living(me) )
                return notify_fail("「裂石穿金」只能在战斗中使用。\n");

 if( (int)me->query("max_force") < 600 )
                return notify_fail("你的内力修为还不够高！\n");

     if( (int)me->query("force") < 200 )
                return notify_fail("你现在的内力不足！\n");

     if( skill < 70)
                return notify_fail("你灵幡魑魅伞的修为不够，不能使用「裂石穿金」! \n");

   if( skill2 < 50)
                return notify_fail("你光明心法的修为不够，不能使用「裂石穿金」! \n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "umbrella")
                return notify_fail("「裂石穿金」必须用伞才能施展。\n");
        if(me->query("family/family_name")!="灵界")
                return notify_fail("你非灵界弟子，无法使用「裂石穿金」。\n");

 
    if (skill<100 || weapon->query("endure")<100)
        {
msg = BLINK HIY"$N忽然向后疾退两步，气沉丹田力贯伞身，霎时伞身碎裂，犹如「裂石穿金」，无数伞影向$n飞射而去。\n\n"NOR;
                message_vision(msg, me, target);
                ob = me->query_temp("weapon");
                destruct(ob);
 
                ap = (int)((me->query("combat_exp"))*(me->query("cor")));
  dp = (int)(((target->query("combat_exp"))*(target->queryr("cor")))/2);

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = RED "$n一个躲闪不及，无数伞影已然嵌在了$n的身上，$n惨叫一声，脸上露出极为痛苦的表情。\n\n"NOR;
                        message_vision(msg, me, target);
                        qi_wound = 100 + skill + random(skill*2);

                        if(qi_wound > target->query("kee")) qi_wound = (target->query("kee") + 1);
                        target->add("kee", -qi_wound);
                        target->add("eff_qi", -(qi_wound/4));
                        COMBAT_D->report_status(target, 0);
  me->start_busy(1+random(2));
                        me->add("force",-400);
                }
                else
                {
                        msg = HIG "只见$n不敢怠慢，脚一点地疾飞冲天，堪堪躲过了这满天的伞影。\n\n"NOR;
                        message_vision(msg, me, target);
me->start_busy(1);
                        me->add("force",-100);
                }

                call_out("perform_jiaoyang", 10, me);
                return 1;
        }
      else if(skill<100 && weapon->query("endure")>=100)
        {
                msg = BLINK HBRED "$N忽然向后疾退两步，手腕一振就要施展灵幡伞中的绝技“裂石穿金”，却不料功力不
足，居然没有震碎手中$w。\n" NOR;
                msg += HIR "$n刚要躲闪，突然发现机会难得，立时又扑了上来。\n\n";
                message_vision(msg, me, target);
                me->add("force",-50);
me->start_busy(1+random(3));
        }
        else
        {
                msg = WHT "$N突然向后疾退两步，力惯"+weapon->query("name")+WHT"，伞影吞吐，手腕一振，竟然使出了灵幡伞中的“裂石穿金”，万把伞罩向$n。\n\n" NOR;
                message_vision(msg, me, target);

                ap = ((me->query("combat_exp"))*(me->query("con")));
             dp = ((target->query("combat_exp"))*(target->query("con")))/10;

                if( dp < 1 )
                        dp = 1;
                if( random(ap) > dp )
                {
                        msg = HIR "$n一个躲闪不及，万道伞影恰如无数金针刺在了$n的身上，$n惨叫一声，脸
上露出极为痛苦的表情。\n\n"NOR;
                        message_vision(msg, me, target);
                        qi_wound = 100 + skill + random(skill*2);

                        if(qi_wound > target->query("kee")) qi_wound = (target->query("kee") + 1);
                        target->add("kee", -qi_wound);
                        target->add("eff_qi", -(qi_wound/4));
                        COMBAT_D->report_status(target, 0);
   me->start_busy(1 + random(1));
                        me->add("force",-400);
                }
                else
                {
                        msg = HIG "只见$n不敢怠慢，脚一点地疾飞冲天，堪堪躲过了这满天的伞影。\n\n"NOR;
                        message_vision(msg, me, target);
   me->start_busy(2);
                        me->add("force",-100);
                }

                return 1;
        }

        return 1;
}
