//chanshen.c by yushu 2001.1
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
       string msg;
       int delay;
    if( !target ) target = offensive_target(me);
    if( !target
       ||       !target->is_character()
       ||       !me->is_fighting(target) )
         return notify_fail("你不在战斗中，不能使用「恶鬼缠身」！\n");

        if((int)me->query_skill("hellfire-whip", 1) < 50)
                return notify_fail("你的烈火鞭级别还不够，使用这一招会有困难！\n");

       if (me->query_skill_mapped("force")!="tonsillit")
                return notify_fail("「恶鬼缠身」必须配合摄气诀才能使用。\n");
	if((int)me->query("max_force") < 500)
		return notify_fail("你的内力不够！\n");
	if((int)me->query("sen") < 250)
		return notify_fail("你的精神不足，没法子施用外功！\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "已经被你缠上了，你还想缠阿！\n");

        msg = HIY "$N招法一变，一招「恶鬼缠身」直甩向$n！\n"NOR;
	me->add("sen", -100);
	me->add("force", -200);
if( random(me->query("combat_exp")) > random((int)target->query("combat_exp"))*3/4) {
                msg += HIR"结果$n被缠上了！\n" NOR;
                delay=(int)me->query_skill("hellfire-whip", 1) /5;
if ( delay > 8 ) delay = 8;
if ( delay < 3  ) delay = 3;
                target->start_busy(delay);
                me->start_busy(1);
        } else {
                msg += HIW"可是$n看破了$N企图躲开了。\n" NOR;
                
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}

