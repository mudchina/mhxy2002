// invocation.c

inherit SSERVER;

int cast(object me, object target)
{       
        int invocation_time;
        object soldier;

        if( !me->is_fighting() )
                return notify_fail("只有战斗中才能召唤刽子手！\n");
        
        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
            return notify_fail("现在开封没有空闲的刽子手来保护你。\n");

        if( (int)me->query("mana") < 300 )
                return notify_fail("你的法力不够了！\n");

        if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神无法集中！\n");

        message_vision("$N喃喃地念了几句咒语。\n\n", me);

        me->add("mana", -100);

        if( random(me->query("max_mana")) < 80 ) {
                message("vision", "但是什么也没有发生。\n",
environment(me));
                return 1;
        }

        soldier = new("/obj/npc/guizi_shou");
        soldier->move(environment(me));
        soldier->invocation(me);
        soldier->set_temp("invoker",me);
        me->set("last_invocation",time());
        me->start_busy(2+random(2));

        return 8+random(5);
}
