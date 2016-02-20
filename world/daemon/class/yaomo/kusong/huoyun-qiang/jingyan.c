
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,skill;
        object weapon;
 	skill = me->query_skill("huoyun-qiang",1);
if( (string)me->query("class") !="bonze")
       return notify_fail("不知道怎么回事,你好象忘了这招枪法!!\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 	return notify_fail("此招只能在战斗中对对手使用！\n");
 	if (skill< 100 ) 
 	return notify_fail("你的火云枪法等级不够！\n");
        if (me->query("force")<800 )
              return notify_fail(" 你的内力不足,如何施展这招绝学? \n");
        weapon = me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "spear")
 		return notify_fail("你所使用的兵器不对！\n");
 	me->add_temp("apply/attack",skill);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 	me->add_temp("apply/attack",-skill);
 	me->add("force",-200);
 	me->start_busy(1);
 	return 1;
}
