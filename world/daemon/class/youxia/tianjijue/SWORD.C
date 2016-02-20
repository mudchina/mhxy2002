// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

// arrow.c
#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;
        success_adj = 100;
        damage_adj = 100;

        if((int)me->query_skill("spells") < 20 )
                return notify_fail("你的法术不够高！\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
         return notify_fail("你要对谁施展伏魔紫剑？\n");

        if((int)me->query("mana") < 100+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("你心魔幢幢，施法必遭反噬！\n");

        me->add("mana", -25-(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 40 ) {
        write("你心神不坚，灵气无法成形！\n");
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
        HIM "$N口中喃喃地念著咒文，手中一团紫光渐渐扩大，灵动无比！\n只听$N大喝一声“邪魔辟易！”，紫光化为一道光剑，一闪间疾刺向$n！\n" NOR,
        //initial message
        HIR "结果「嗤」地一声，紫光从$n身上透体而过，拖出长长的七彩光气。光气绕了回来，散入$N的体内！\n" NOR,
        //success message
        HIM "$n摈除心魔，结果「嗤」地一声，紫光从$n身上透体而过，无声无息地钻入地下！\n" NOR,
        //fail message
        HIM "但是$n道心坚定，法力高强。紫光一顿，「嗤」地一声折向$N！\n" NOR,
        //backfire initial message
        HIR "结果紫光化为万千细箭，射入$n全身，顿时血花飞溅！\n" NOR
        //backfire hit message. note here $N and $n!!!
        );
        me->start_busy(1+random(2));
        return 3+random(5);
}

