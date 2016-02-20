//By tianlin@mhxy for 2001.9.30
//请不要抄!
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 140;
	damage_adj = 130;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail(CYN"你要对谁使用"YEL"道家"BLINK+HIR"仙火"NOR+CYN"？\n"NOR);

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail(CYN"你的法力不够！\n"NOR);

	if((int)me->query("sen") < 20 )
		return notify_fail(HIC"你的精力无法集中！\n"NOR);

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write(MAG"糟糕,没发出来！\n"NOR);
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		YEL "$N口中念了几句咒文，口中喷出了"NOR+HIR"【"NOR+HIW"“"NOR+BLINK+HIW"熊熊大火"NOR+HIW"”"NOR+HIR"】"NOR+YEL"\n只见大火很快的喷到$n的头顶,过了好一会才熄灭！\n" NOR,
			//initial message
		HIC "结果$n已经被烧得不成人样了！\n" NOR, 
			//success message
		HIW "但是$n在一瞬间躲了过去。\n" NOR, 
			//fail message
		HIB "但是大火被$n以法力一引，反而朝$N这边喷了过来！\n" NOR, 
			//backfire initial message
		HIC "结果$n已经被烧得不成人样了！\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

       me->start_busy(1+random(1));
       target->start_busy(1+random(2));
       return 3+random(4);
}

