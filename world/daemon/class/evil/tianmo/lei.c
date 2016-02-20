// mo.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 110;
        damage_adj = 110;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要用紫靓神雷打谁？\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("你无法集中精力，别砸中自己了！\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("遭了,魔鬼们全跑了！\n");
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
                "both",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIC "$N口中念了几句咒文，半空中一阵愁云密布，风云突变\n突然出现一条青色的闪电，呼！地一声向$n当头劈下！\n" NOR,
                        //initial message
                HIC "结果$n轰了个正着！\n" NOR, 
                        //success message
                HIY "但是$n身形一闪，躲开了这一击。\n" NOR, 
                        //fail message
                HIR "但是神雷被$n以法力反震之下，反而劈到了$N！\n" NOR, 
                        //backfire initial message
                HIR "结果轰了个正着！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}
