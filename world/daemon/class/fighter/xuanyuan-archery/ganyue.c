// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("lengquan-force",200);
        if ( extra < 100) return notify_fail("你的［冷泉神功］还不够纯熟！\n");
        tmp = me->query_skill("xuanyuan-archery",200);
        if ( tmp < 50 )return notify_fail("你的［轩辕箭］还不够纯熟！\n");
        if((int)me->query("max_force") < 2400 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1600 )
             
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 350 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                               
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［流星赶月］只能对战斗中的对手使用。\n");
        me->add_temp("apply/attack",tmp);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIR"$N使出轩辕箭－－－总决式！！\n\n\n$N手握"+weapon->query("name")+HIR"用出一招［百步穿杨］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(BLK"$N手握"+weapon->query("name")+BLK"用处一招［李广搭弓］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(GRN"$N手握"+weapon->query("name")+GRN"用处一招［糟毛子射雕］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(BLU"$N手握"+weapon->query("name")+BLU"用处一招［糟毛子射鸟］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(WHT"$N手握"+weapon->query("name")+WHT"用处一招［糟帽子射鸡］向$n打去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIG"$N手握"+weapon->query("name")+HIG"用处一招［糟毛子射猪］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(MAG"$N手握"+weapon->query("name")+MAG"用处一招［鸡飞蛋打］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIC"$N手握"+weapon->query("name")+HIC"用处一招［不会编了］向$n射去！\n\n"NOR,me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        message_vision(HIB"$N手握"+weapon->query("name")+HIB"用处一招［没词了］向$n射去！\n\n"NOR,me, target);
        target->start_busy(1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->receive_damage("kee", 100);
        
        me->add("force", -1200);
        
        me->start_busy(1);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
        return 1;
}