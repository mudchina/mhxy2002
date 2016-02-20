//modify by ken the new 十万神魔
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int addon, tmp, atk;
        object weapon;
        extra = me->query_skill("tianmo-blade",1);
        if ( extra < 120) return notify_fail("你的天魔连环八式还不够纯熟！\n");

        addon = me->query_skill("dimo-steps",1);
        tmp= me->query_skill("force",1);
        if ( addon < 120 )return notify_fail("你的地魔连环八步还不够纯熟！\n");
        if ((int)me->query("force")<1000)
                return notify_fail("你的内力不足了。\n");
        
        if(me->query("family/family_name") != "魔教")
                return notify_fail("你省省好了。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("没事别乱用十万神魔。\n");
        
        atk = (addon+tmp)/2;
        me->add_temp("apply/attack",atk);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIW"\n$N神气贯通，将天魔连环八式精髓一气呵成！\n "NOR, me,target);
        message_vision(HIR"万魔初醒！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"魔光乍现！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"万刃天魔！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"万魔归宗！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM"$n使出天魔连环八式收手式，手中的魔刃迅捷无比地砍向$N的。\n"NOR,target,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-atk);
        me->add_temp("apply/damage",-extra);
        me->add("force",-500);
me->start_busy(random(1));
        return 1;
}
