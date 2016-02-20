// qi_poison.c
//#include <ansi.h>

int update_condition(object me, int duration)
{
   int damage_kee=30, damage_sen=30;

  if(me->query("max_kee")>200)
     damage_kee=me->query("max_kee")/5;
   if(me->query("max_sen")>200)
     damage_sen=me->query("max_sen")/5;
        if(damage_kee > 300) damage_kee = 300;
        if(damage_sen > 300) damage_sen = 300;
   me->receive_wound("sen", damage_sen);
   me->receive_wound("kee", damage_kee);
   me->set_temp("death_msg","体内多余真气未能趋散，心脉寸断而死。\n");
   me->apply_condition("qi_poison", duration - 1);
   if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
     message_vision("$N的脸似乎因为疼痛而扭曲了！\n", me);
   else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
     message_vision("$N胸口忽然发出砰的一声巨响\n", me);     
   else 
     message_vision("$N似乎站不稳了。\n", me);
     
   if( duration < 1 ) return 0;
   return 1;
}


