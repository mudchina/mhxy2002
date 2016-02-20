// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

    success_adj = 155;
       damage_adj = 125;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展万鼠蚀天？\n");

           if((int)me->query_skill("yaofa") < 25 )
           return notify_fail("你的妖法太烂了。。。\n");   
        if((int)me->query("mana") < 150+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 150 )
                return notify_fail("你无法集中精力！\n");
                

        me->add("mana", -150-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 120);

        if( random(me->query("max_mana")) < 50 ) {
                write("看来小耗子们今天都睡觉去了。\n");
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
                HIR "\n$N口中喃喃念了几句，顿时不知道从哪里窜出无数老鼠，疯狂的向$n潮水般的涌去！\n" NOR,
                        //initial message
                HIR "\n只听得$n惨叫连连，在鼠群的撕咬下血肉模糊，惨不忍睹！\n" NOR, 
                        //success message
                HIR "$n奋力的甩掉身上的无数老鼠，虽然没有受伤，但还是被搞的颇为狼狈。\n" NOR, 
                        //fail message
                HIR "$n大喝一声，鼠群似乎被其气势所摄，反向$N扑去！\n" NOR, 
                        //backfire initial message
                HIR "鼠群从$n身上践踏而过，拖出满地鲜血，$n被咬的体无完肤！\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}

