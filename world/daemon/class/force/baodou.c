//by tianlin 2001.8.1

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;


        skill = me->query_skill("force",1);

	if( skill > 250 ) {
		skill=250;
	}

        if( target != me ) 
		return notify_fail(""HIC"爆豆"NOR"只能给自己使用。\n");

   //     if( (int)me->query("force") < skill*2 )     
	//	return notify_fail("你的内力不够。\n");
        if((int)me->query("bellicosity") < 1000 )
                return notify_fail(HIY"你的"NOR+HIR"杀气"NOR+HIY"不足以发挥自己的"HIC"超能力"NOR+HIY"！\n"NOR);
        if( (int)me->query_temp("baodou") ) 
		return notify_fail(HIC"你已经在"BLINK+HIR"爆豆"NOR+HIC"中了。\n");

        me->add("force", -skill);
        me->receive_damage("kee", 50);

        message_vision(
                HIC "
               "BLINK+HIR"."NOR+HIC" 
               |
           \   *  
          "BLINK+HIR"."NOR+HIC"  "NOR+HIY"* * *"NOR+HIC" "BLINK+HIR"."NOR+HIC"
         -=*  POP! *=-              
         "BLINK+HIR"."NOR+HIC"  "BLINK+HIR"."NOR+HIC""NOR+HIY"* * *"NOR+HIC"  "BLINK+HIR"."NOR+HIC"
              *  "BLINK+HIR".\
                                 
               "NOR+HIC"|"NOR""BLINK+HIR"."NOR+RED"\n $N运足全身的力量,"NOR+HIW"轰"NOR+RED"的一声，$N发现$N的周身泛起一片红光，$N感觉自己强壮了很多!    \n" NOR, me);

        me->add_temp("apply/attack", skill/5);
	me->add_temp("apply/strength", skill/5);
          me->add_temp("apply/damage", 200);
        me->add("bellicosity",- 1000);
        me->set_temp("baodou", 1);

        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/5 :), skill);

        if( me->is_fighting() ) me->start_busy(1);//设定在战斗中的busy数目,在这里我给busy数设为1

        return 1;
}

void remove_effect(object me, int amount)
{
        if(!me) return;
        me->add_temp("apply/attack", - amount);
	me->add_temp("apply/strength", - amount);
        me->delete_temp("baodou");
          me->add_temp("apply/damage", - 200);
        me->add("bellicosity", amount*2 );
	// mon 3/1/98. move this to after powerup is done.
        tell_object(me, HIY"你的"NOR+HIC"超能量"NOR+HIY"已经发挥完毕。\n"NOR);
}

