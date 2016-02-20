#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)

  {
//              string msg;
        object weapon = me->query_temp("weapon");
        int cost = me->query_skill("qianjun-bang", 1)/2;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("牵制攻击只能对战斗中的对手使用。\n");

        if(!living(target))
                return notify_fail("这人本来就不能动,还用什么大圣醉酒？\n");
        if(!weapon || weapon->query("skill_type") != "stick" )
                return notify_fail("你手中没有棒子，如何使得「大圣醉酒」字诀？\n");
        if(me->query_temp("YSJL/chan"))
                return notify_fail("你正在使用「大圣醉酒」字诀。\n");
        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
        if( (int)me->query_skill("qianjun-bang", 1) < 100 )
                return notify_fail("你的千钧棒法极不够娴熟，不要丢人现眼了。\n");
              if(me->query_temp("last_zuijiu")+5>time())
                return notify_fail("你刚刚使过「大圣醉酒」,先歇一歇吧。\n");
        if( me->query("force") <= 500 )
                return notify_fail("你的内力不够！\n");
        if( me->query("max_force") <= 700 )
                return notify_fail("你的内力修为不够！\n");
        if(me->query_temp("combat_wield"))
                return notify_fail("你没拿棒子，何以使出「大圣醉酒」？\n");
        if (me->query_skill_mapped("stick") != "qianjun-bang")
                 return notify_fail("你现在无法使用「大圣醉酒」。\n");
        if(userp(me)){
    
            if( (int)me->query_skill("wuxiangforce", 1) < 100 )
                return notify_fail("你的无相神功修为不够，不能把手中兵器化作「大圣醉酒」。\n");
            if( me->query_skill_mapped("force") != "wuxiangforce")
                return notify_fail("你所用的内功与千钧棒法意气相悖！\n");
            }
        me->add("force", -cost);
        me->add("mana", -10);

        message_vision(CYN"\n$N默运无相神功,但见手中从"+weapon->name()+CYN"招呼过来，中间有强烈的酒味，在空中着一圈圈漂着，
久久不散，你睁着眼，闭着眼假装醉啦，突然只见天上有一条条大棒向$n砸来！\n\n"NOR, me, target);
        if( ((random(me->query("combat_exp")) + (me->query("combat_exp")/4) > (int)target->query("combat_exp")*1/2 ))) {
                message_vision(HIW"$n一不留神被砸个正着,当时目瞪口呆。\n"NOR,me, target);
                target->start_busy(3);
                me->start_busy(random(2));
        } else {
                message_vision(HIY"可是$p看破了$P的企图，并没有上当。\n" NOR, me, target);
                me->start_busy(random(1));
        }
                                                 
        me->set_temp("last_zuijiu",time());
        return 1;
}
