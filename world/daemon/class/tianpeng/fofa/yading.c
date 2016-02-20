//by tianlin 2001.7.30
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;


	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你要对谁施展"HIY"天猪压顶"NOR"？\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
		write("糟糕，没法出来,FUCK！\n");
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
		HIW "\n$N口中念了句咒文，半空中出现"HIY"老猪"NOR+HIW"的身影，"HIY"老猪"NOR+HIW"一个空翻，来了一个旷世绝招。\n这招叫做"BLINK+HIM"死猪跳楼"NOR+HIW"，在$n的头顶狠狠的压过！\n" NOR,
			//initial message
		CYN "\n\n                         _//|.-~~~~-,
                       _/66  \       \_@
                      (')_   /   /   |
  "HIB"我是笨猪我怕谁?!"NOR+CYN"      '--'|| |-\  /
                           //_/ /_/ \n" NOR, 
			//success message
		HIC "\n谁知$n的体积太小没有压上，真实可惜。\n" NOR, 
			//fail message
		HIC "但是老猪被$n用力一踢，一个飞燕向$N飞了过来,一头栽在$N的头顶上！\n" NOR, 
			//backfire initial message
		HIC "你大喊一声: "BLINK+HIR"疼\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

