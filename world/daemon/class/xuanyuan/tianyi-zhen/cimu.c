//By tianlin@mhxy for 2002.1.20

#include <ansi.h>
#include "/daemon/skill/eff_msg.h";
inherit SSERVER;
int perform(object me, object target)
{
    string str;//谣言的变量
    int damage,p;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail(HIR"「刺目」"NOR"只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("tianyi-zhen", 1) < 80 )
        return notify_fail(WHT"你天一神针不够娴熟，使不出「刺目」。\n"NOR);
    if ((int)me->query("max_force")<400)
        return notify_fail(RED"你内力修为不足，无法运足内力。\n"NOR);
    if ((int)me->query("force")<200)
    {
        return notify_fail(HIC"你现在内力不够，没能将「刺目」使完！\n"NOR);
    }
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "needle")
       msg = HIC "$N左手两指并拢，手臂暴长，迅捷异常分刺$n双目，\n"NOR;
    else
       msg = HIC "$N手中神针一振，剑尖一点暴长，分刺$n左右双目，\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3|| 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
    {
        me->start_busy(1);
        target->start_busy(random(4));
        damage = (int)me->query_skill("tianyi-zhen", 1) + (int)me->query_skill("needle", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("kee", damage);
        target->receive_wound("kee", damage);
        msg += HIC"$n只看到寒尖一点，双目一阵剧痛，眼前一黑，就什么也看不见
了，顿时长声痛极而呼！\n"NOR;
        p = (int)target->query("kee")*100/(int)target->query("max_kee");
        msg += "( $n"+eff_status_msg(p)+" )\n";
        message_vision(msg, me, target); 
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=GRN+target->name()+HIM"被"HIY+me->name()+HIM"用"NOR+MAG"轩辕古墓"NOR+HIW"绝学"HIR"「"HIW"刺目无痕"HIR"」"HIM"杀死了, 据说"GRN+target->name()+HIM"到了阴间双目还流血不止!";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
        me->add("force", -damage/5);
	me->set_temp("zhen/cimu", 1);
	target->set_temp("block_msg/all",1);
	call_out("cimu_end", (int) 2+random(6), me, target);
    } else
    {
        me->start_busy(2);
        msg += HIY"$p情急智生，抬手也$P右眼刺去，迫得$P回剑跃开。\n"NOR;
        message_vision(msg, me, target); 
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}

void cimu_end(object me, object target)
{      
       if(!living(target)) 
       return;
	target->enable_commands();
	message_vision("$N抹了抹流着"HIR"鲜血"NOR"，终于能看见了。\n", target);
	target->set_temp("block_msg/all", 0);
	me->delete_temp("zhen/cimu");

	return;
}
