// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, myexp, hisexp;
        object weapon;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("huoyun-qiang",100) ;
        if ( extra < 50) return notify_fail("你的火云枪还不够纯熟！\n");
                
     if(me->query("family/family_name")!="火云洞")
           return notify_fail("“［火龙术］”只有火云洞门人才可以用！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［火龙术］只能对战斗中的对手使用。\n");
        weapon = target->query_temp("weapon");
        myexp = (int)me->query("combat_exp");
        hisexp= (int)target->query("combat_exp");
        if(random(hisexp) < myexp * 2 && weapon)        
        {
        message_vision(
HIW "\n\n$N使出一式火云枪中的 ［火龙缠身］ ，枪身似一条火龙般缠住$n手中的兵刃,"+ 
weapon->name()+  "脱手而飞！\n\n" NOR, me,target);
        if( weapon->unequip()) weapon->move(environment(target));
        }
        else
        {
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR+ "\n\n$N使出一式火云枪中的 ［火龙飞天］ ，手中的"+(me->query_temp("weapon"))->name()+"如火龙般直咬$n的$l！\n\n"+ NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        }
        return 1;
}