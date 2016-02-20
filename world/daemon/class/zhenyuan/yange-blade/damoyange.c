//by yushu@MHXY 2001
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
                return notify_fail("你要对谁施展这一招「大漠雁歌」？\n");

        if(!me->is_fighting())
                return notify_fail("「大漠雁歌」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 800 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query("combat_exp") < 1500000 )
                return notify_fail("你的武学还不够！\n");

        if((int)me->query_skill("yange-blade", 1) < 160)
                return notify_fail("你的「雁歌刀法」还不够纯熟！\n");

        if((int)me->query_skill("taiyi", 1) < 160)
                return notify_fail("你的太乙仙法级别还不够，使用这一招会有困难！\n");
               
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("大漠雁歌必须配合镇元神功才能使用。\n");
          
        me->delete("env/brief_message");
        target->delete("env/brief_message");

        message_vision(HIW"\n$N倒吸一口真气，大喝一声，使出天地也为之变色的「大漠雁歌」！\n"NOR,me,target);

        me->set_temp("YGD_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("YGD_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("YGD_perform");
        me->receive_damage("sen", 300);
        me->add("force", -400);
 
         if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
             
        me->start_busy(5);
        return 1;
}


