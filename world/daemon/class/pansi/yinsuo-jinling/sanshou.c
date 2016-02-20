#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int j;
       string msg;
      int ap;
        if( !target ) target = offensive_target(me);
j = (int)me->query_skill("yinsuo-jinling",1);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招三无三不手??\n");

        if(!me->is_fighting(target) )
                return notify_fail("三无三不手只能在战斗中使用!!\n");

        if((int)me->query("max_force") <1000 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 500 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") <50 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("yinsuo-jinling",1) <120)
        return notify_fail("你的银索金铃级别还不够施展这一招三无三不手!!\n");
if((int)me->query_skill("yueying-wubu",1) <100)
        return notify_fail("你的月影舞步等级不够!!\n");
if((int)me->query_skill("jiuyin-xinjing",1)<100)
        return notify_fail("你的九阴心经等级太低!!\n");
        if((int)me->query_skill("pansi-dafa",1) <120)
        return notify_fail("你的盘丝大法等级不够!!\n");
//      if( (string)me->query("gender") !="女性")
//       return notify_fail("你非为纯阴之身,怎能知哓女儿家的心思??\n");
  if(me->query("family/family_name") != "盘丝洞" )
return notify_fail("你不是盘丝洞弟子,领悟不到鞭法的精髓!!\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

        ap = 2 + random(1);
     msg = HIC
"\n问世间情为何物?直叫人生死相许!$N心中一阵酸楚,鞭法忽然变得灵动异常!\n" NOR;
    message_vision(msg, me, target);

        if( (int)me->query_skill("yinsuo-jinling",1) > 180)
{
        me->set_temp("YSJL_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YSJL_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("YSJL_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->start_busy(ap);
       } else {
      if( (int)me->query_skill("yinsuo-jinling",1) > 150)
{
      me->set_temp("YSJL_perform", 2);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->set_temp("YSJL_perform", 4);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       me->start_busy(2);
} else {
       me->set_temp("YSJL_perform", 5);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
     me->start_busy(1);
}
}
        me->delete_temp("YSJL_perform");
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                //        else target->kill_ob(me);
                }
        }

        return 1;
}
