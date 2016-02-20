//fumo by greenwc
//fomo by yushu修改
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
              int i,j,e,damage,damagea;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要攻击谁？\n");

        if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if((int)me->query("max_force") < 200 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("force") < 100 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("xianfeng-spells", 1) < 50)
                return notify_fail("你的仙风云体术等级不够，不能使用这一招！\n");
        i=(int)me->query_skill("sword");
              j=(int)target->query_skill("dodge");
              e=i+j+i/2;
        if(i<75)        
        return notify_fail("你的剑法级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");
        target->delete("env/brief_message");
        message_vision(HIC"\n$N口中默念御剑口诀，手中"+weapon->name()+NOR+HIC"顿时间霞光四射，一招「御剑伏魔」直斩$n！\n\n"NOR,me,target);
        if (random(e)>j)
        {       
        damage = i+random((int) me->query("max_force"))/30;
        damagea = i+random((int) me->query("max_force"))/50;
         target->receive_damage("kee",damage*2);
         target->receive_damage("sen",damagea*2);
        me->receive_damage("sen", 100);
        me->add("force", -100);
        me->receive_damage("kee", 100);
        COMBAT_D->report_status(target);
        COMBAT_D->report_sen_status(target);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
             }      
          me->start_busy(2);
        return 1;
}
