//降龙四式 by hawks 2000.12
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void pili_ok(object);
int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「降魔四式」？\n");
      

        if(!me->is_fighting())
                return notify_fail("「降魔四式」只能在战斗中使用！\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("staff",1)<120)
                return notify_fail("你的基本杖法级别不够!\n");
if((int)me->query_skill("fumo-zhang",1)<100)
                return notify_fail("你的伏魔杖级别还不够，使用这一招会有困难！\n");
        if (me->query_skill_mapped("force")!="zhenyuan-force")
                return notify_fail("降魔四式必须配合镇元神功才能使用。\n");
        if((int)me->query_skill("zhenyuan-force",1)<100)
                return notify_fail("你的镇元神功级别还不够，无法使用这一招!\n");
                

                if(me->query_temp("no_xiangmo"))
                        return notify_fail("你刚刚用过「降魔四式」了！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");

message_vision(HIY"\n$N加快身形，疾风般向$n展开连续进攻！\n"NOR,me,target);
        me->set_temp("FMZ_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("FMZ_perform", 2);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("FMZ_perform", 3);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         me->set_temp("FMZ_perform", 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("FMZ_perform");

        me->receive_damage("sen", 140);
        me->add("force", -140);
me->start_busy(random(3));
        me->set_temp("no_xiangmo",1);
                call_out("xiangmo_ok",5+random(3),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

void xiangmo_ok(object me)
{ if (!me) return;
      me->delete_temp("no_xiangmo");
}