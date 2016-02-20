#include <ansi.h>
#include <combat.h>

inherit SSERVER;
// inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
int skill;
  skill=(int)me->query_skill("baguazhen", 1);
        if( target != me )
        return notify_fail("你只能将［八门化身］用在自己的身上。\n");
        if( (int)me->query("force") < 300 ) 
        return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("huashen") )
        return notify_fail("你已经在施展［八门化身］了。\n");
	if( me->query_temp("weapon") )
		return notify_fail("你只有放下武器才能使出这一招。\n");
        if( (int)me->query_skill("baguazhen", 1) < 40 ) 
		return notify_fail("你的八卦阵法太差了，还使不出这一招！\n");
	if( (int)me->query_skill("wuxing-quan", 1) < 40 ) 
		return notify_fail("你的五行拳法太差了，还使不出这一招！\n");
        if( (int)me->query_skill("taiyi", 1) < 40 ) 
		return notify_fail("你的太乙仙法太差了，还使不出这一招！\n");
        message_vision( HIR"$N轻啸一声，使出八卦阵法中的［八门化身］，人影闪动间，$N身行飘乎不定！\n" NOR, me);
        me->add("force", -150);
        me->add_temp("apply/dodge", skill/5);
        me->add_temp("apply/attack", skill/5);
        me->add_temp("apply/defense", skill/5);
        me->set_temp("huashen", 1);
 me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :),skill/2);
        if( me->is_fighting() ) me->start_busy(4);
        return 1;
}
void remove_effect(object me, int amount)
{       amount=((int)me->query_skill("baguazhen", 1)/5);
        me->add_temp("apply/dodge", - amount);
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/defense", - amount);
        me->delete_temp("huashen");
        tell_object(me, "你的［八门化身］施展完毕，身法渐定了。\n");
return;
}
