//by tianlin 2001.5.1
//这是我自己做者玩的个perform,这些词是我从别的招上抄下来的.xixi
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;
	object weapon=me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「"HIY"倒乱"NOR+HIC"七星"NOR"」只有在战斗中才能使用。\n");

	if( (int)me->query_skill("skyriver-rake", 1) < 40 ) 
	return notify_fail(HIB"你的天河耙法级别还不够高深!\n"NOR);

          if(me->query("family/family_name") != "天蓬帅府" )
                return notify_fail("你是哪儿偷学来的武功，也想使用！\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"。已经中了你的假动作了!\n");

	message_vision(RED"$N拿着"RED+weapon->name()+RED"对$n作了一个假动作。
\n"NOR,me, target);

	mypot=(int)me->query_skill("rake");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

	time=(int)me->query_skill("skyriver-rake", 1) /5;
	if ( time > 15 ) time = 15;
	if ( time < 5  ) time = 5;

	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIC"$N一时着急，"BLINK+HIW"想跑"NOR+HIC".但是脚下一个不稳，被一块石头给绊倒了！\n"NOR,target);
		target->start_busy(time);
	}else {
	message_vision(HIY"但是$N看破你的意图，对你的攻势毫无理会！\n"NOR,target,
me);
                me->start_busy(1+random(3));
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}

