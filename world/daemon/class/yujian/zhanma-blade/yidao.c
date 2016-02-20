#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)

                return notify_fail("你要对谁施展这一招「一刀斩」？\n");
        if(!me->is_fighting())

                return notify_fail("「一刀斩」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
             
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
               if (me->query_skill_mapped("force")!="zanglong-force")

                return notify_fail("一刀斩必须配合藏龙心法才能使用。\n");


   i=(int)me->query_skill("zhanma-blade",1)+(int)me->query_kar();
        if( i < 120)

                return notify_fail("你的斩马刀级别还不够，使用这一招会有困难！\n");

   me->delete("env/brief_message");
   message_vision(HIW"\n$N双手举刀,$N大喝一声～～一刀斩～!!!\n"NOR,me);
   target->delete("env/brief_message");

        me->set_temp("XFJ_perform", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        target->start_busy(3);

        me->delete_temp("XFJ_perform");

        me->receive_damage("sen", 200+random(200));
        me->add("force", -500);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
        me->start_busy(2);
}