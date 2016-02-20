// jinglei.c 弹指惊雷
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, weapon2, target;
	int skill, dp, wound;

	target = me->select_opponent();

        skill = me->query_skill("tanzhishentong",1);

	if( !(me->is_fighting() ))
                return notify_fail("「"HIG"弹指惊雷"NOR"」只能在战斗中使用。\n");

	if ( objectp(weapon = me->query_temp("weapon")))
                return notify_fail("「"HIG"弹指惊雷"NOR"」必须空手使用。\n");

	if( skill < 100)
                return notify_fail("你的弹指神通等级不够, 不能使用「"HIG"弹指惊雷"NOR"」！\n");

        if( me->query("force") < 150 )
                return notify_fail("你的内力不够，无法运用「"HIG"弹指惊雷"NOR"」！\n");
 
message_vision(HIC"$N使出弹指神通之"HIG"「弹指惊雷」"HIC", 顿时眼内精光暴射，出手攻向$n的全身穴位！\n"NOR,me,target); 
 
	dp = target->query("combat_exp");
	if( dp < 1 )
		dp = 1;
	if( random(me->query("combat_exp")) > random(dp)) 
	{
		if(userp(me))
                        me->add("force",-150);
message_vision( HIR"$n只觉得眼前一花，气海穴上微微一痛，全身真气狂泄而出！\n"NOR,me,target); 
        weapon = target->query_temp("weapon");
                 if(objectp(weapon))
                {
message_vision(HIR"同时手腕一麻，手中武器脱手而出！\n"NOR,me,target); 
                       weapon->move(me);
               }
		wound = 300 + random(200);
                if((int)target->query("force") < wound)
                        wound = target->query("force");
                target->add("force", -wound);
                target->receive_wound("sen", wound/5);
		target->start_busy(4);
		me->start_busy(1);
		COMBAT_D->report_status(target);

	}
	else
	{
                msg = HIC"可是$n的看破了$N的企图，立刻采取守势，使$P的「弹指惊雷」没有起到作用。\n"NOR;
		me->start_busy(2);
	}

	if(!target->is_fighting(me)) target->fight_ob(me);

	return 1;
}
