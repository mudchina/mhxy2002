// 群龙无首
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        int skill, skill1, skill2;
        object weapon1, weapon2;

        if(!target) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「群龙无首」？\n");

        if(!me->is_fighting())
                return notify_fail("「群龙无首」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500)
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 250)
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("huntian-hammer",1) < 80)
                
return notify_fail("你的混天锤级别还不够，使用着一招会有困难!\n");

        if((int)me->query_skill("fengbo-cha",1) < 80)
        return notify_fail("你的风波十二叉级别还不够，使用这一招会有困难!\n");

        if((int)me->query_skill("dragonfight",1) < 80)
                return notify_fail("你的龙形搏击级别还不够，使用这一招会有困难!\n");

        weapon1=me->query_temp("weapon");
        weapon2=present("fork", me);
        if(!objectp(weapon2)) 
                return notify_fail("兵器都没有拿全怎么显现这一招的威力?\n");

        message_vision(HIC"\n$N后退一步，运气于双手，猛然托天而举，慢慢的幻化出了真身，化做神龙冲天而起，顿时雷电交加，$N就势打出了「群龙无首」的六招。\n"NOR, me, target);

        me->set_temp("BWQ_perform", 1);
        COMBAT_D->do_attack(me, target, weapon1);

        message_vision(HIC"\n趁着$n正忙于招架，$N拿出"+weapon2->query("name")+"击出两下"NOR, me, target);

        weapon1->unequip();
        weapon2->wield();

        me->set_temp("FBC_perform", 2);
        COMBAT_D->do_attack(me, target, weapon2);

        me->set_temp("HTC_perform", 3);
        COMBAT_D->do_attack(me, target, weapon2);

        
message_vision(HIC"\n趁着$n正忙于招架，$N放下"+weapon2->query("name")+"舍身攻出三招"NOR, me, target);

        weapon2->unequip();

        me->set_temp("DRF_perform", 2);
        COMBAT_D->do_attack(me, target,weapon1);

        me->set_temp("HTC_perform", 3);
        COMBAT_D->do_attack(me, target, weapon1);

        
me->set_temp("HTC_perform", 8);
        COMBAT_D->do_attack(me, target, weapon1);

        
me->delete_temp("FBC_perform");

        me->receive_damage("sen", 100);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        weapon2->unequip();
        weapon1->wield();
        me->start_busy(3);

        return 1;
}
