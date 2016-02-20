#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int addon, tmp;
        object weapon;
        extra = me->query_skill("bingpo-blade",1);
        if ( extra < 90) return notify_fail("你的冰魄寒刀还不够纯熟！\n");
        dodskill = (string) me->query_skill_mapped("dodge");
        if ( dodskill != "xiaoyaoyou")
                        return notify_fail("寒光一气需要逍遥游的配合！\n");
        addon = me->query_skill("xiaoyaoyou",1);
        if ( addon < 90 )return notify_fail("你的逍遥游还不够纯熟！\n");
        tmp = me->query_skill("ningxie-force",1);
        if ( tmp < 90 ) return notify_fail("你的冰谷凝血功造诣不足！\n");
        if ((int)me->query("force")<900)
                return notify_fail("你的真气不够！\n");
        if ((int)me->query("combat_exp") < 2000000 )
                return notify_fail("你的道行不够！不能够娴熟的施展这个工夫。\n");
        
        if(me->query("family/family_name") != "大雪山")
                return notify_fail("你不是雪山弟子，这寒光一气的奥义似乎难以运用！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(BLU"「寒光一气」"NOR"只能对战斗中的对手使用。\n");
        
        weapon = me->query_temp("weapon");
        me->add_temp("apply/damage",extra/2);
        me->add_temp("apply/attack",tmp/2);
        message_vision(HIW"\n$N手中$n"HIW"自下而上从天划过，一时间漫天飞雪！！\n"NOR,me,weapon);
        message_vision(HIY"飘雪式---$N手中$n"HIY"顺着雪势使出一招！\n"NOR,me,weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_vision(HIC"排雪式---$N手中$n"HIC"犹如扑风追影反撩！\n"NOR,me,weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_vision(HIB"劈雪式---$N手中$n"HIB"夹着翩翩刀光猛劈！\n"NOR,me,weapon);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"));
        message_vision(HIW"$N自空中回落地面，冷酷的脸在$n"HIW"的寒光中更加阴沉！\n"NOR,me,weapon);
        me->add_temp("apply/damage",-extra/2);
        me->add_temp("apply/attack",-tmp/2);

        me->add("force",-300);
        me->start_busy(3);
        return 1;
}

