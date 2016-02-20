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
    
  if( !living(target) )
  return notify_fail(target->name() + "已经倒在地上了。\n"); 

  if((int)me->query("mana") < 200 )
     return notify_fail("你的法力不够。\n");

   if((int)me->query("sen") < 20 )
     return notify_fail("你现在神智不清，不能施展这法术。\n");

   me->add("mana", -200);
   me->receive_damage("sen", 20);

   if( random(me->query("max_mana")) < 50 ) 
   {
     write("咦？这一次好像不灵。\n");
     return 1;
   }
  
  message_vision (HIW "$N念动真言，用手向$n一指，喝声：“疾”！$n顿时觉得立脚不住，一头栽倒在地。\n" NOR, me, target);
  target->remove_call_out("unconcious");
  target->unconcious();
  return 1;
}