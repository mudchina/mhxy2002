// lingxi.c 灵犀一指

#include <ansi.h>

inherit SSERVER;

#include <combat.h>

int perform(object me, object target)
{
	string msg;
	object weapon;
	int damage, p;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「"HIY"灵犀一指"NOR"」只能对战斗中的对手使用。\n");

        if(me->query("family/family_name") != "江湖浪子" )
                return notify_fail("你是哪儿偷学来的武功，也想用「"HIR"凤舞九天"NOR"」?\n");

        if( (int)me->query_skill("lingxiyizhi", 1) < 100 )
                return notify_fail("你的灵犀一指不够娴熟，无法使用「"HIY"灵犀一指"NOR"」。\n");

	weapon = me->query_temp("weapon");
	if (weapon) return notify_fail("灵犀一指须空手使用。\n");

        if ( (int)me->query("force") < 500)
                return notify_fail("你的内力不够，无法使用「"HIY"灵犀一指"NOR"」。\n");

        msg = HIY "$N双手一前一后，缓缓伸出，中指突地一弹，两道劲风汇成一股，“咝咝”有声，直袭$n前胸。\n"NOR;

        damage = (int)me->query_skill("lingxiyizhi", 1) + (int)me->query_skill("unarmed", 1) + 100;
	damage += random(damage / 2);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
                msg += HIR"$n躲闪不及，“噗”地一声，被指劲击中前胸！\n"NOR;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage / 3);
                p = (int)target->query("kee") * 100 / (int)target->query("max_kee");
		msg += RED "$n胸口一阵巨痛，大叫倒地！\n" ;
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
                msg += HIC"$n向旁边一闪，让过了劲风，没想到这股指劲竟然有回力，从$n背后倒转回来，正刺中$p的后背。\n"NOR;
                target->receive_damage("kee", damage / 3);
                target->receive_wound("kee", damage / 9);
                p = (int)target->query("kee") * 100 / (int)target->query("max_kee");
		msg += RED "$n觉的胸口有点痛！\n" ;
	}
	else {
                msg += HIC"$n向旁边一闪，让过了劲风，却忽然发觉这股指劲竟然有回力，匆忙中只好一个前扑才堪堪躲过，模样狼狈之极。\n" NOR;
	}
	message_vision(msg, me, target);
        me->add("force", -300);
        me->start_busy(2);

	return 1;
}
