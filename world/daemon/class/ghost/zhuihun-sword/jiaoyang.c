// By tianlin 2001.5.1
//我觉着加力0也太少了,所以设enforce 50这样挺好.(snicker)
#include <ansi.h>

inherit SSERVER;
string msg;

int perform(object me, object target)
{
        object weapon,ob;
        int skill;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("「"HIR"娇"HIC"阳"HIM"似"HIY"火"NOR"」只能在战斗中使用。\n");

        if( me->query("force_factor") > 50)
                return notify_fail("「"HIR"娇"HIC"阳"HIM"似"HIY"火"NOR"」绝技不允许加最大的力,请enforce 50以内。\n");
   
        if( (int)me->query_skill("tonsillit", 1) < 120 )
                return notify_fail("你的「摄气心法」不够娴熟，不会使用「娇阳似火」。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("「"HIR"娇"HIC"阳"HIM"似"HIY"火"NOR"」必须用剑才能施展。\n");
	if(me->query_temp("last_jiaoyang")+5>time())
		return notify_fail("你刚刚使过「"HIR"娇"HIC"阳"HIM"似"HIY"火"NOR"」,先歇一歇吧。\n");

        if( (int)me->query_skill("zhuihun-sword", 1) < 120 )
                return notify_fail("你的「追魂剑」不够娴熟，不会使用「娇阳似火」。\n");
        if( (int)me->query("force") < 1000  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("zhuihun-sword");
        msg =  HIY "$N清啸一声,使出"HIR"「追魂剑」"NOR+HIY"中的绝技「"BLINK+HIR"娇"HIC"阳"HIM"似"HIY"火"NOR+HIY"」发魔般地向$n刺出"BLINK+HIC"八"NOR+HIY"剑！\n"NOR;
        message_vision(msg, me, target);

        me->add("force", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();

        msg = WHT"●日●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = WHT"●出●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = MAG"●东●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = MAG"●方●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIG"●娇●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIG"●阳●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●似●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);
        msg = HIR"●火●！\n"NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 100);

        if( me->is_fighting() ) me->start_busy(0);
        me->set_temp("last_jiaoyang",time());
        return 1;
}
