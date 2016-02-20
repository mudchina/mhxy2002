//疾风魔狼刀
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int addon, tmp, atk;
        object weapon;
        extra = me->query_skill("tianlang-blade",1);
        if ( extra < 150) return notify_fail("你的天狼夜魔刀还不够纯熟！\n");

        addon = me->query_skill("shouya-force",1);
        tmp= me->query_skill("force",1);
        if ( addon < 120 )return notify_fail("你的兽牙魔经还不够纯熟！\n");
        if ((int)me->query("force")<1000)
                return notify_fail("你的内力不足了。\n");
        
        if(me->query("family/family_name") != "天空界")
                return notify_fail("你省省好了。\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("没事别乱用疾风魔狼刀。\n");
        
        atk = (addon+tmp)/2;
        me->add_temp("apply/attack",atk);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIW"\n$N神气贯通，将兽牙魔经运转成熟，身体急旋施展出疾风魔狼刀的绝技！\n "NOR, me,target);
        message_vision(HIC"刀光犹如狂风暴雨般砸向$n\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM"$N在暴风雨般的刀光中飘摇不定，最后$n聚万道刀光和一迅捷无比的砍向$N！！！\n"NOR,target,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-atk);
        me->add_temp("apply/damage",-extra);
        me->add("force",-500);
        me->start_busy(random(2));
        return 1;
}


