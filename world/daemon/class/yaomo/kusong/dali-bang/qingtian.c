#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「大力擎天」？\n");

        if(!me->is_fighting())
                return notify_fail("「大力擎天」只能在战斗中使用！\n");
        if(me->query("family/family_name")!="火云洞")
                return notify_fail("你非火云弟子，无法使用「大力擎天」。\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("「大力擎天」必须配合火魔心法才能使用。\n");
                
if((int)me->query_skill("huomoforce",1) <100)
                return notify_fail("你的火魔心法级别还不够，使不出「大力擎天」！\n");
	if((int)me->query("force") < 500 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("dali-bang", 1) < 100)
                return notify_fail("你的大力棒法级别还不够，使用这一招会有困难！\n");

        if(me->query_temp("qt_busy")) 
               return notify_fail("你刚用过大力擎天，还事等会再用吧..\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIY"\n$N大吼一声，犹如晴天霹雳，猛的祭出了大力棒的杀手绝学「大力擎天」!\n"NOR,me,target);

        me->set_temp("DLB_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("DLB_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("DLB_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("DLB_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("DLB_perform");

        target->receive_damage("kee",((int) me->query("str")*10));
        target->receive_wound("kee",((int) me->query("str")*10));


        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->set_temp("qt_busy",1);
        call_out("remove_effect",5+random(3),me);
        me->start_busy(2);
        return 1;
}


void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("qt_busy");
}