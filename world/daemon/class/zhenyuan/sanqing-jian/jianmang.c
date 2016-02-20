#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
    int ap, myexp, yourexp, extra;
        object weapon;
     
 if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("灵幻剑芒只能在战斗中使用.\n");
        if(me->query("family/family_name")!="五庄观")
return notify_fail("你又不是五庄观的，你怎么这么不要脸！\n");
   if((int)me->query_skill("sanqing-jian",1) < 80)
    return notify_fail("你的三清剑法等级还不够!!\n");
   if( (int)me->query("max_force") < 800)
   return notify_fail("你的内力太弱,不能吐出剑芒!!\n");
   if( (int)me->query("force") < 400)
   return notify_fail("你的内力不够了!!\n");
        if(! me->query_temp("weapon"))
                return notify_fail("你必须用剑才能使用「"+HIR"灵幻剑芒"NOR+"」！\n");
    ap = (int) me->query("spi");
    myexp = (int)me->query("combat_exp");
    yourexp = (int)target->query("combat_exp");
   msg = HIC
"\n$N一声朗笑,手中长剑斜指向天,剑尖吐出一团尺余的银芒,似有灵性般吞缩不定!\n"
"$n正诧异间,那团剑芒却猛得暴涨,朝着$n的面门直射而来!!\n\n" NOR;
message_vision(msg, me ,target);
    if( random(myexp*5) > yourexp)
{
   msg = HIR
"\n只听$n一声惨嚎,剑芒从$n的额头掠过,带出一缕血光!!\n" NOR;
message_vision(msg, me ,target);
   msg = HIW
"\n剑芒长虹经天般自天际处转得一转,又飞回$N的身边.\n" NOR;
message_vision(msg, me ,target);
 target->start_busy(2+random(3));
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
me->start_busy(1);

}
else {
  msg = HIY
"\n$n却识得那团剑芒的厉害,早已远远避在一边.\n" NOR;
message_vision(msg, me ,target);
me->start_busy(2);
}
me->add("force",-120);
        return 1;
}
