//By tianlin@mhxy for 2002.1.3

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;//谣言的变量
	 object weapon=me->query_temp("weapon");                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「 "CYN"刀 "RED"剑 "YEL"笑"NOR" 」？\n");

        if(!me->is_fighting())
                return notify_fail("「"CYN"刀"RED"剑"YEL"笑"NOR"」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("kee") < 500 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("kugu-blade", 1) < 60)
                return notify_fail("你的枯骨刀法修为不够深！\n");
	if(me->query_temp("last_xiao")+5>time())
		return notify_fail("绝招多使就不灵了。\n");
        me->delete("env/brief_message");
	target->delete("env/brief_message");

	if (! present(target,environment(me))) return 1;
       message_vision(HIB"\n$N默运混天气功，突然间使出七修剑法，手中"+weapon->name()+NOR+HIB"直取$n！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
       message_vision(HIC"\n$N不等招式用老，诡异一笑，立刻收刀出爪，一股阴风直扑$n！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+HIM"被"+me->name()+HIM"用"NOR+YEL"陷空山"NOR+HIM"绝学"HIR"「刀剑笑」"HIM"打死了，据说"+target->name()+HIM"到死脸上还挂着微笑！";
	                message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
	               }
        me->receive_damage("kee", 50);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("last_xiao",time());
        return 1;
}

