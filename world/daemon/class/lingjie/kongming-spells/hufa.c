//lingjie hufa
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int invocation_time;
        object soldier;

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤护法。\n");

        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
            return notify_fail("你刚叫过护法，他们都被你叫烦了！\n");

        if((int)me->query_skill("kongming-spells",1) < 50)
                return notify_fail("你的空明心法不够，无法召唤护法..\n");

        if( (int)me->query("mana") < 200 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");

        message_vision(HIM"$N仰头望天，大声叫到：灵界护法，速来护驾...\n"NOR, me);

        me->add("mana", -150);
        me->receive_damage("sen", 80);

        if( random(me->query("max_mana")) < 250 ) {
                message_vision(HIB"但是什么也没有发生。\n"NOR);
                return 1;
        }

        seteuid(getuid());
        if((int)me->query("daoxing") > 500000) {
        soldier = new("/d/lingjie/npc/hufa0");
        } else if((int)me->query("daoxing")>250000) {
        soldier=new("/d/lingjie/npc/hufa1");
        } else {
        soldier=new("/d/lingjie/npc/hufa2");
        }
        soldier->move(environment(me));
        soldier->invocation(me);
        soldier->set_temp("invoker",me);
        me->set("last_invocation",time());
        me->start_busy(1+random(2));

        return 8+random(5);
}
