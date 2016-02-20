// shexue.c 摄气，摄取阳气。weiqi...
#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
        int qi_gain, qi_lost, ap, dp, success;
        string msg;     

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
        return notify_fail("你想对谁使用摄心诀？\n");
    
        if( target == me ) return notify_fail("吸自己？\n");

        if(target->query_temp("netdead")) return notify_fail("趁火打劫，不太像话吧？\n");

        if( (int)me->query_skill("huaxue-force", 1) < 30 )
                return notify_fail("你的化血神功修为太低，不能使用摄心诀。\n");

        if( (string)me->query("family/family_name") != "乱石山碧波潭" )
                return notify_fail("你不会化血神功，不能使用摄心诀。\n");

        if(!me->is_fighting()||!target->is_fighting())
                return notify_fail("只能在战斗中摄取阳气。\n");

        if( (int)me->query("kee")  > 3*(int)me->query("max_kee")/2 )
                return notify_fail("你现在气太过充盈，再吸就要爆炸了。\n");

        qi_lost = target->query("kee") / 5;

        if(qi_lost < 5 )
                return notify_fail("对方的血已经吸干了。\n");
        
        msg = HIC
"\n$N偷偷运起化血神功，结果$n被化血神功罩住，体力被吸走了！\n" 
NOR;

        success = 1;

        ap = me->query_skill("force");
        ap = ap * ap * ap /10 ;
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared exp and force level. 
        //note: has nothing to do with target's force level.

        ap = (int)me->query("max_mana");
        dp = (int)target->query("max_mana");
        if( random(ap + dp) < dp ) success = 0;
        //here we compared max_mana, 法力高强应该不怕鬼。

        if(success == 1 ){
                msg +=  HIC "结果$n头皮一麻，只觉得体内体力源源不断地流了出去！\n" NOR;
                qi_lost=qi_lost-random(qi_lost/2);
                target->receive_damage("kee", qi_lost, me);

                qi_gain = qi_lost;
                if( (int)target->query("max_kee") < (int)me->query("max_kee") )
                        qi_gain = qi_gain * (int)target->query("max_kee")/(1+(int)me->query("max_kee"));
                //here, the more the max_kee of your target, the more the qi_gain.
                //and always qi_gain <= qi_cost.

                if( (int)target->query("combat_exp") < (int)me->query("combat_exp") )
                        qi_gain = qi_gain * (int)target->query("combat_exp")/(1+(int)me->query("combat_exp"));
                //here, we decrease the qi_gain futher more according to dao-xing so she-qi from too weak players or NPCs is useless.
                if( qi_gain > 0 ) me->add("kee", qi_gain);

                //here also add some huaxue-force point.
                if( qi_gain > 0 
                && (int)me->query("combat_exp") < (int)target->query("combat_exp") 
                && (int)me->query_skill("huaxue-force",1) <= 150
                && random(10) < 1 )
                {
                        me->improve_skill("huaxue-force", qi_gain);
//                      tell_object(me, "A\n");
                } else {
//                      tell_object(me, "B\n");
                        qi_gain=qi_gain/5;
                        if( qi_gain < 0 ) qi_gain =1;
                        me->improve_skill("huaxue-force", qi_gain, 1);
                }
        } else {
                msg +=  HIC "结果$n一扭头，避了开去！\n" NOR;   
        } 

        message_vision(msg, me, target);
        if( success == 1 ) COMBAT_D->report_status(target);

//he'll try kill you...
        if( living(target) ) target->kill_ob(me);

        me->start_busy(1);        
        return 1;
}