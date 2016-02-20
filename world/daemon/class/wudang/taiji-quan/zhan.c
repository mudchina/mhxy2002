// zhen.c 太极拳「粘」字诀
// snowman
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) || !living(target))
                return notify_fail("「粘」字诀只能对战斗中的对手使用。\n");

//        if(!me->query_temp("taiji"))
//                return notify_fail("太极拳精要在于将展未展，你没有运用「太极」，又如何能使用「粘」字诀？\n");
        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在真气不够，强行使用「粘」是发挥不了它的威力的！\n");                   
        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     
        if( target->is_busy())
                return notify_fail("对方正自顾不暇呢，你不忙使用「粘」字诀。\n");   
                
        msg = CYN "\n$N一招一式节节贯串，如长江大河，"RED"「粘」"CYN"在$n身上，一个圆圈跟着一个圆圈，
大圈、小圈、平圈、立圈、正圈、斜圈，一个个太极圆圈发出，连绵不断，滔滔不绝！\n"NOR;
        
        if(random(me->query("combat_exp")) > target->query("combat_exp")/2){
                damage = (int)me->query_skill("taiji-quan", 1)/20; 
                damage = 2+random(damage);
                if(damage > 7) damage = 7; 
                target->start_busy(damage);
                me->add("neili", -(damage*40));
                me->add("jing", -50);
                msg += HIR"这左圈右圈登时便套得$p跌跌撞撞，身不由主的立足不稳，犹如中酒昏迷！\n"NOR;       
                } 
        else{
                me->start_busy(3);
                me->add("jing", -25);
                me->add("neili", -150);
                msg += HIY"$p只觉在$P太极拳笼罩之下，无可抵御，只得只得运劲于足，飘然闪开。\n"NOR;
             }
        message_vision(msg, me, target);
        return 1;
}
