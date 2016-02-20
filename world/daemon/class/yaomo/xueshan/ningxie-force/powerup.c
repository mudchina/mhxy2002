// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


         skill = me->query_skill("ningxie-force",1);

        if( skill > 250 ) {
                skill=250;
        }

        if( target != me ) 
                return notify_fail("你只能用凝血神功提升自己的战斗力。\n");

        if( (int)me->query("force") < skill*2 )     
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("你已经在运功中了。\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIR "$N微一凝神，运起凝血神功，忽听一声清啸，$N身形急转犹如陀螺。\n" NOR, me);

        me->add_temp("apply/attack", skill/5);
        me->add_temp("apply/strength", skill/5);
        me->set_temp("powerup", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(3);

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
        me->add_temp("apply/strength", - amount);
        me->delete_temp("powerup");
//    me->add("bellicosity", amount*2 );
        // mon 3/1/98. move this to after powerup is done.
        tell_object(me, "你的凝血神功运行一周天完毕，将内力收回丹田。\n");
}
