// tianlei.c 

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int damage;
        string msg;
        object weapon;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("琴剑双绝只能对战斗中的对手使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
		return notify_fail("手中无剑,你怎么使得出琴剑双绝！\n");

        if( (int)me->query_skill("liangyi-jian", 1) < 200 )
		return notify_fail("你的两仪剑法还未练成，不能使用！\n");

        if( (int)me->query("force", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用琴剑双绝！\n");	

    msg = HIY "\n$N忽然仰天大喝一声“琴 剑 双 绝”，手上的剑如风车般连环击出，一阵热浪随剑势狂飙而出，势不可挡！\n"NOR;

	if( weapon = target->query_temp("weapon") ){
    if (random(me->query_skill("force")) > target->query_skill("force")/2|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{  
    msg += HIM"\n$p只觉得浑身一热，手掌虎口巨痛，手中"
                + target->query_temp("weapon")->query("name") + "脱手而出。\n" NOR;
		message_vision(msg, me, target);
		(target->query_temp("weapon"))->move(environment(target));
	} else {
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
		message_vision(msg, me, target);
	}
	me->start_busy(1);
        }
        else
        {
        if (random(me->query_skill("force")) > target->query_skill("force")/2 )
	{
		me->start_busy(3);
		target->start_busy(random(3));
		
		damage = (int)me->query_skill("sword", 1);
		
		damage = damage*4 + random(damage);
		
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage);
		
		if( damage < 300 ) msg += HIY"\n结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n结果重重地击中，$n「哇」地一声吐出一口鲜血！\n"NOR;
        	else if( damage < 500 ) msg += RED"\n结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n"NOR;
        	else msg += HIR"\n结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n"NOR;
		
	} else 
	{
		me->start_busy(1);
    msg += HIY"\n$p危急中突然伏地翻滚而出，避过了这致命一击，已吓得脸色苍白！\n" NOR;
	}
	message_vision(msg, me, target);

        }
        me->add("force", -600);
	return 1;
}
