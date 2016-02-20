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
        addon = me->query_skill("dimo-steps",1);
        tmp= me->query_skill("force",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("没事别乱用十万神魔。\n");

        if(me->query("family/family_name")!="魔教")
               return notify_fail("就凭你也想偷学本门上乘决学没门！\n");

        if((int)me->query_skill("tianmo-blade", 1) < 100)
                return notify_fail("你的天魔刀法不纯属，使用不出来这一招！\n");

        if(me->query_temp("pfm_busy_shenmo")+6>time())
                return notify_fail("你刚刚唤醒十万神魔，还是等下再叫吧。\n");

        atk = (addon+tmp)/2;
        me->add_temp("apply/attack",atk);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIR"万魔初醒！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"魔光乍现！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"万刃天魔！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"天魔七现！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"魔焰万丈！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"天魔独尊！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"万炼魔瘴！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"万魔归宗！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM"$n使出天魔连环八式收手式，手中的魔刃迅捷无比地砍向$N的。\n"NOR,target,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-atk);
        me->add_temp("apply/damage",-extra);
        me->set_temp("pfm_busy_shenmo",time());
        return 1;
}
