//modify by ken
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("〖夺魂〗只能对战斗中的对手使用。\n");
        if( target == me ) return notify_fail("你疯了？\n");
        extra = me->query_skill("tigerfight",1) ;
        if(extra < 50 ) return notify_fail("你的天虎掌修练不精，再怎么运也不运不出来！\n");
        if( (string)me->query("family/family_name") != "魔教" )
              return notify_fail("你又不是魔族，怎能吸人精血？\n");
        if( (int)me->query("mana") < 400 )
              return notify_fail("你的法力不足，再怎么吸也吸不动。");
        msg = HIG "\n$N逆运天魔大法，双掌发出一道耀眼的绿光刺的$n睁不开眼！" NOR;
        if(random((int)me->query("mana")) >= (int)target->query("mana")/2)
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIG "$N只觉得眼前一阵群魔乱舞，元神几乎要脱窍而出！\n" NOR,target);
        target->receive_wound("sen",extra);
        me->receive_curing("sen",extra);
        me->add("mana",-200);
        COMBAT_D->report_status(target);

        }       
        else{
        message_vision(msg+"\n",me,target);
        message_vision( HIB "$N大笑道：雕虫小计，也拿来现丑！\n" NOR,target);
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("mana",-300);
        }
        me->start_busy(2);
        return 1;
}
