#include <ansi.h>
#include <condition.h>
inherit F_CLEAN_UP;
int update_condition(object me, int duration)
{
   if( !living(me) ) {
      message("vision", me->name() + "突然感到一阵奇冷。\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然一阵刺骨的奇寒袭来，你中的冰魄寒毒发作了！\n" NOR );
      message("vision", me->name() + "的身子突然晃了两晃，牙关格格地响了起来。\n",
            environment(me), me);
   }
       me->receive_damage("kee",50);
        me->add("kee",-110);
      me->apply_condition("bp_poison", duration - 1);
   if( duration < 1 ) return 0;
   return CND_CONTINUE;
}
