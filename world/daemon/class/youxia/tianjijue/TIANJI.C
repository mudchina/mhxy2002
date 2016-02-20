// jushu.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 150;
	damage_adj = 140;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail(HIR "你要对谁施展天机咒？\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail(HIR "你的法力不够，施展天机咒！\n");

        if((int)me->query("sen") < 200 )
                return notify_fail(HIR "你无法集中精力，无法施展天机咒！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 100);

	if( random(me->query("max_mana")) < 50 ) {
                write(HIC "你咒语念错了，没有施展出天机咒！\n");
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
                HIY "$N口中喃喃地念著咒文，手中一团紫光渐渐扩大，灵动无比！
只听$N大喝一声“天机咒！”，阵阵咒语声传向$n！\n" NOR,
			//initial message
                HIY "\n$n被震的口吐鲜血，跌倒在地！\n" NOR, 
			//success message
                HIY "但是$n好像聋子一样，什么也没有听到似的。\n" NOR, 
			//fail message
                HIR "咒文被$n以法力一引，反而传入$N的耳朵里！\n" NOR, 
			//backfire initial message
                HIR "\n$n被震的口吐鲜血，跌倒在地！\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(2+random(0));
	return 1+random(2);
}

