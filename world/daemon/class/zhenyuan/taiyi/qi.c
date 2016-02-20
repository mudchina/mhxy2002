#include <ansi.h>

inherit SSERVER;

 int cast(object me, object target)
{
   string msg;
   if( !target ) target = offensive_target(me);

   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||   target==me)
    return notify_fail("你要对谁施展法术？\n");
  
  if( me->query("spell_shushan_on") != 1 )
  return notify_fail("你还未得我蜀山派的真传。\n");
  
   if(living(target) )
  return notify_fail(target->name() + "现在很清醒。\n"); 

  if((int)me->query("mana") < 10 )
     return notify_fail("你的法力不够。\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("你现在神智不清，不能施展这法术。\n");

   me->add("mana", -10);
   me->receive_damage("sen", 10);

   if( random(me->query("max_mana")) < 25 ) 
   {
     write("咦？这一次好像不灵。\n");
     return 1;
   }
  message_vision (HIW "$N念动真言，用手向$n一指，大喝一声：“$n不起，更待何时！”\n" NOR, me, target);
  target->remove_call_out("revive");
  target->revive();
  //target->reincarnate();
  message_vision (HIW "$n伸臂屈膝，从地上一跃而起。\n" NOR, me, target);
  return 1;
}