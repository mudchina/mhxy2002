// Jiz
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 55;
        damage_adj = 45;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要引水神袭击谁？\n");

        if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你无法集中精力！\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 50);

        if( random(me->query("max_mana")) < 50 ) {
                message_vision(HIM"$N口中念念有词。。。但什么也没有发生！\n"NOR,me);
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
HIM"\n$N后退几步，口中念了几句咒文，大叫一声：“无穷的大海呀!帮我战胜$n吧!”说罢！之间一道水柱冲天！水神出现了！只见水神向$n放了几个水波!\n"NOR,
                        //initial message
HIR"\n结果$n躲避不及，被水波激个正着！\n"NOR,
                        //success message
HIC"\n结果被$n躲开了。\n"NOR,
                        //fail message
HIR"但水势被$n以法力反激，反向$N射去！\n" NOR,
                        //backfire initial message
HIR"\n结果$n躲避不及，被水柱激个正着！\n"NOR,
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(3+random(2));
        return 3+random(5);
}