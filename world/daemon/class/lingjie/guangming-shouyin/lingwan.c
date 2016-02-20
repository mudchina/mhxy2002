//link 2001.2.20
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("「灵丸」只能对战斗中的对手使用。\n");

    if( (int)me->query_skill("guangming-force", 1) < 150 )
   return notify_fail("你的光明心法火候不够，使不出「灵丸」。\n");

    if( (int)me->query_skill("guangming-shouyin", 1) < 150 )
   return notify_fail("你的光明手印不够熟练，不能使用灵丸」。\n");

    if( (int)me->query_skill("fengtian-steps", 1) < 150 )
   return notify_fail("你的风天神紫云步不够熟练，不能使用灵丸」。\n");

    if( (int)me->query_skill("lingfan-san", 1) < 150 )
   return notify_fail("你的灵幡魑魅伞不够熟练，不能使用灵丸」。\n");

    if( (int)me->query_skill("libieyu", 1) < 150 )
   return notify_fail("你的离别羽不够熟练，不能使用灵丸」。\n");

    if( (int)me->query_skill("kongming-spells", 1) < 150 )
   return notify_fail("你的空明灵法不够熟练，不能使用灵丸」。\n");

    if( (int)me->query("force") < 1000 )
   return notify_fail("你的内力修为还不够高。\n");

    if(me->query("family/family_name")!="灵界")
                return notify_fail("你非灵界弟子，无法使用「灵丸」。\n");


    msg = HIW "
$N将全身每个气海光球各涌出三分之一，分为两道纳入两条手臂中，。\n"NOR+HIC"
眼看劲力逐渐凝聚，身旁的气劲却越旋越快，回旋的劲力与$N护身的气劲碰触到，直是嘎然作响，
忽然同时轰然的爆裂开来，两道粗大凝结如实物一般的光球，撕裂空间般的往$n狂奔而去。。\n"NOR;  
   if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2) { 
   me->start_busy(3);
   damage = ((int)me->query_skill("guangming-shouyin", 1))*2.5+(int)me->query_skill("guangming-force",1);
   damage = damage/2 + random(damage);
   target->receive_damage("kee", damage);
   target->receive_wound("kee", damage/random(5));
   me->add("force", -600);
   msg += HIR"
能量相击之下，$n马上被$N狂龙一般的内劲瞬间吞噬，两股光球轰然的击到了$n的身上。\n"NOR;
    } else
    {
       me->start_busy(2);
       msg += HIY"可是$p看破了$P的企图，早就闪在了一边,不过也惊出一身冷汗。\n"NOR;
    }
 message_vision(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
