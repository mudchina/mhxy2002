// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 50;
        damage_adj = 50;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施剑剑剑？\n");

        if((int)me->query("mana") < 300+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 400 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 500 ) {
                write("看来剑仙今天没空。\n");
                return 1;
        }
        

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "qi",           
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "\n$N口中念了句咒文，半空走出一位容貌俊琅的剑仙，双手各持一把剑。剑忽然脱手，闪出三道剑光射向$n！\n" NOR,
                        //initial message
                HIR "\n结果「嗤」地一声，金光从$n身上透体而过，\n拖出一条长长的血洞，直射到两三丈外的地下！\n" NOR, 
                        //success message
                HIC "结果呛！地一声$n躲过了三把飞剑。\n" NOR, 
                        //fail message
                HIC "但是剑光被$n以法力反激，反向$N射去！\n" NOR, 
                        //backfire initial message
                HIR "结果剑光从$n身上透体而过，拖出一条长长的血洞，直射到两三丈外的地下！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}