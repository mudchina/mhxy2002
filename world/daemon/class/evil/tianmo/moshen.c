// heart_sense.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( !target || !target->is_character() )
                return notify_fail("你要对谁使用魔啸？\n");
        if( target->is_corpse() )
                return notify_fail("来不及了，只有活人才能救醒。\n");
        if((int) me->query_skill("tianmo",1) < 80)
                return notify_fail("你的天魔大法不够高深！");
        if( (int)me->query("mana") < 2000 ) return notify_fail("你的灵力不够！\n");
        if( me->query("sen") <= 300 )
                return notify_fail("你的神不够！\n");
        me->receive_damage("sen", 30);
        me->add("mana", -500);
        message_vision( HIY "$N一手放在$n的天灵盖上, 一手贴在$n的后心, 闭上眼睛缓缓低吟...\n" NOR, me, target);
        if( random(me->query("max_mana")) > 100 )
                target->revive();
        else
                me->unconcious();
        if( me->is_fighting() )
                me->start_busy(3);
        return 1;
}
