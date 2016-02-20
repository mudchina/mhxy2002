//Cracked by Roath

//Ansi 99.12
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int i;
        int f_time;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「心动三剑」？\n");

        if(!me->is_fighting())
                return notify_fail("「心动三剑」只能在战斗中使用！\n");
        if(me->query("family/family_name")!="蜀山派")
                return notify_fail("不是蜀山的不能用「心动三剑」！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 300 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("yujianshu", 1) < 80)
                return notify_fail("你的心剑修为还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
   target->delete("env/brief_message");

        me->add_temp("apply/attack", (int)(me->query_skill("yujianshu",1)/6));
        me->add_temp("apply/damage", (int)(me->query_skill("yujianshu",1)/6));
message_vision(HIG"\n$N集中精神，施展心剑的「心动三剑」，向$n发动会心攻击！\n"NOR,me,target);
message_vision(HIG"\n第一剑，自上而下！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIG"\n第二剑，从左到右！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIG"\n第三剑，旋转而至！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->add_temp("apply/attack", -(int)(me->query_skill("yujianshu",1)/6));
        me->add_temp("apply/damage", -(int)(me->query_skill("yujianshu",1)/6));
        me->receive_damage("sen", 100);
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(2);
        return 1;
}
