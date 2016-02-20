// powerup.c 猕猴内功加力
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
   int skill;
   if( target != me )
   return notify_fail("你只能用猕猴内功来提升自己的战斗力。\n");
   if( (int)me->query("force") < 300  )
   return notify_fail("你的内力不够。\n");
   if( (int)me->query_temp("powerup") )
   return notify_fail("你已经在运功中了。\n");
   skill = me->query_skill("mihou-force",1);
   me->add("force", -200);
   message_vision(
   HIY "$N微一凝神，运起猕猴内功，全身灌满真气，衣裳无风自舞，毛发根根立起，气势迫人。\n" NOR,me);
//   me->add_temp("apply/attack", skill/5)
//   me->add_temp("apply/attack", skill/5);
   me->add_temp("apply/dodge", skill/5);
   me->set_temp("powerup", 1);
   me->start_call_out((:call_other, __FILE__, "remove_effect", me, skill/5:), skill);
   if( me->is_fighting() ) me->start_busy(3);
   return 1;
}
void remove_effect(object me, int amount)
{
//   me->add_temp("apply/attack", - amount);
   me->add_temp("apply/dodge", - amount);
   me->delete_temp("powerup");
   tell_object(me, "你的猕猴内功运行完毕，将内力收回丹田。\n");
}
