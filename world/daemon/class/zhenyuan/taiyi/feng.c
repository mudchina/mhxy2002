// dingshen.c 定身法
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, howlong;

	if( !target ) target = offensive_target(me);

      if((int)me->query_skill("spells") < 50)
               return notify_fail("你还没学会封咒术。\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
          return notify_fail("你想把谁的法术暂时封住？\n");

  if(target->query_temp("fu_no_cast"))
          return notify_fail(target->query("name")+"的法术已经被暂时封闭了！\n");

	if((int)me->query("mana") < 500 )
		return notify_fail("你的法力不够！\n");

   if((int)me->query("sen") < 30 )
		return notify_fail("你无法集中精力！\n");

     me->add("mana", -300);
	me->receive_damage("sen", 10);

  msg = HIY"$N念动真言，朝$n一指，喝一声“疾”！\n" NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /10 ;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");
     if( random(ap + dp) < dp/2+random(dp/2) ) success = 0;
//here we compared exp and spells level. 
//note: has nothing to do with target's spells level.

	ap = (int)me->query("max_mana");
	dp = (int)target->query("max_mana");
     if( random(ap + dp) < dp/2+random(dp/2) ) success = 0;
//here we compared max_mana.

	ap = (int)me->query("mana");
	dp = (int)target->query("mana");
     if( random(ap + dp) < dp/2+random(dp/2) ) success = 0;
//here we compare current mana. this is important. you need recover to try again.

	howlong = 0;        
	if(success == 1 ){
     msg +=  HIC "结果$n只觉的一阵头晕，顿时口不能开！\n" NOR;
        target->set_temp("fu_no_cast", 1);
	
		howlong = 15 + random((me->query_skill("spells") -100));
		if(howlong>60) howlong=60;
//a typical level is 100+100 ->enabled 150, so will "ding" about 1 minute in the best case.
	}	    
	else {
          msg +=  HIY "$n眉头微微一皱，似乎毫不在意。\n" NOR; 
	} 

	message_vision(msg, me, target);

//he'll try kill you...
	if( living(target) ) target->kill_ob(me);

if (success == 0) {
//me->start_busy(1);
return 1+random(2);
}

//	me->start_busy(5);        
	if( howlong>0 ) call_out("free", howlong, target);
        
	return 3+random(5);
}

void free(object target)
{
   if(target) target->delete_temp("fu_no_cast");     
 message_vision (HIC "$N身上禁咒渐渐失去了作用。\n" NOR, target);
    return;
}

