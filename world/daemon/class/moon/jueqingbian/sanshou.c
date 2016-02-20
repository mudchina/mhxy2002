//By tianlin@Mhxy for 2001.12.30
 
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int j;
       string msg;
      int ap;
        if( !target ) target = offensive_target(me);
j = (int)me->query_skill("jueqingbian",1);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「三无三不手」？\n");

        if(!me->is_fighting(target) )
                return notify_fail("「三无三不手」只能在战斗中使用\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 500 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") <50 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("jueqingbian",1) <120)
        return notify_fail("你的绝情鞭级别还不够施展这一招「三无三不手」!!\n");
if((int)me->query_skill("moondance",1) <100)
        return notify_fail("你的冷月凝香舞等级不够!!\n");
if((int)me->query_skill("moonforce",1)<100)
        return notify_fail("你的园月心法等级太低!!\n");
        if((int)me->query_skill("moonshentong",1) <120)
        return notify_fail("你的月宫仙法等级不够!!\n");
      if( (string)me->query("gender") !="女性")
       return notify_fail("你非为纯阴之身,怎能知哓女儿家的心思??\n");
  if(me->query("family/family_name") != "月宫" )
return notify_fail("你与痴梦无缘,领悟不到鞭法的精髓!!\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

        ap = 2 + random(1);
     msg = HIC
"\n问世间情为何物?直叫人生死相许!$N心中一阵酸楚,鞭法忽然变得灵动异常!\n" NOR;
    message_vision(msg, me, target);

        if( (int)me->query_skill("jueqingbian",1) > 180)
{
        message_vision(HIW"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
        me->set_temp("JQB_perform", 12);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
        me->set_temp("JQB_perform", 13);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        message_vision(HIW"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
        me->set_temp("JQB_perform", 14);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
        me->set_temp("JQB_perform", 15);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(HIW"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
        me->set_temp("JQB_perform", 16);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        message_vision(MAG"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
        me->set_temp("JQB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->start_busy(ap);
       } else {
      if( (int)me->query_skill("jueqingbian",1) > 150)
{
       message_vision(HIW"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 12);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(HIY"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 13);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(HIR"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 14);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(HIG"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 15);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->start_busy(2);
} else {
       message_vision(YEL"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 12);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(CYN"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 13);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       message_vision(MAG"刷的一声,$n好象感觉到一阵微风从耳边吹过\n"NOR,me,target);
       me->set_temp("JQB_perform", 14);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       me->start_busy(1);
}
}
        me->delete_temp("QJB_perform");
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        return 1;
}

