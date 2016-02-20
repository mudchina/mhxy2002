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
                return notify_fail("【血雾】只能对战斗中的对手使用。\n");
        if( target == me ) return notify_fail("你疯了？\n");
        extra = me->query_skill("tigerfight",1) ;
        if(extra < 50 ) return notify_fail("你的天虎掌修练不精，再怎么运也不运不出来！\n");
        if( (string)me->query("family/family_name") != "魔教" )
              return notify_fail("你又不是魔族，怎能吸人精血？\n");
        if( (int)me->query("force") < 400 )
              return notify_fail("你的内力不足，再怎么吸也吸不动。");
        msg = HIR "\n$N逆运血魔神功，双臂渗出一层淡淡的血雾慢慢的向$n全身罩去！" NOR;
        if(random((int)me->query("force")) >= (int)target->query("force")/2)
        {
        message_vision(msg+"\n",me,target);
        message_vision( HIR "$N只觉得身上精血源源不断的向外流出！\n" NOR,target);
        target->receive_wound("kee",extra);
        me->receive_curing("kee",extra);
        me->add("force",-200);
        COMBAT_D->report_status(target);

        }       
        else{
        message_vision(msg+"\n",me,target);
        message_vision( HIY "但是被$N识破了！\n" NOR,target);
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("force",-300);
        }
        me->start_busy(2);
        return 1;
}
