// sanqing.c by yushu@SHXY 2000.11
//by tianlin@mhxy for 2001.9.3修改设上busy time
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
         if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招"HIM"「一剑化三清」"NOR"？\n");

        if( !me->is_fighting() )
                return notify_fail(""HIM"「一剑化三清」"NOR"只能在战斗中使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(""HIM"「一剑化三清」"NOR"必须拿剑！\n");
        if( (int)me->query("force") < 100 )
                return notify_fail("你的内力不够！\n");
     if( time()-(int)me->query_temp("sanqing_end") < 2 )
                return notify_fail(YEL"绝招用多就不灵了！\n"NOR);
        if( (int)me->query_skill("sanqing-jian",1) < 100 )
                return notify_fail("你的三清剑法还不到家，无法使用"HIM"「一剑化三清」"NOR"！\n");
        msg = HIM "$N"HIM"使出五庄观绝技"HIY"「一剑化三清」"HIM"，身法陡然加快,手握剑柄晃成三条白龙！\n" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("sanqing-jian",1)/2);

        me->clean_up_enemy();
        ob = me->select_opponent();

        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        me->add_temp("apply/attack", - (int)me->query_skill("sanqing-jian",1)/2);

       me->add("force", -50);
       me->set_temp("sanqing_end",time());
       me->start_busy(0);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}