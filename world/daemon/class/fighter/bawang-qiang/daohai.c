// jianzhang.c  

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
         int count;
/*
         if ((string)me->query("id")!="shade")
         return notify_fail("这不是你能用的招术!!\n");       
*/
         if( !me->is_fighting() )
         return notify_fail("「翻江倒海」只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != ("spear"))
                return notify_fail("「翻江倒海」开始时必须拿着一杆枪！\n");

        if( (int)me->query("force") < 80 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("lengquan-force",1) < 15 )
                return notify_fail("你的冷泉神功不够！\n");

        if( (int)me->query_skill("spear",1) < 10 ||
            me->query_skill_mapped("spear") != "bawang-qiang")
                return notify_fail("你的霸王枪法还不到家，无法使用翻江倒海！\n");

        msg = HIY "$N使出将军府绝技「翻江倒海」，身法陡然加快，于瞬间接连出招！\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add("force", -100);
        me->start_busy(3);

        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}
