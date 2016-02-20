//concentrate.c 集气诀
//created by foc,23-08-01
//说明：常常觉得内力，法力不够用？用这个吧！


#include <ansi.h>
inherit SSERVER;

int exert(object me, object target)
{
    int effect;
    if(!target) target = me;
    if(target != me) return notify_fail("集气诀没办法作用于他人。\n");
    if(me->is_ghost() || me->is_ghost())
      return notify_fail("你现在没办法使用集气诀。\n");
    if((int)me->query_skill("segokee",1)<20)
    return notify_fail("你的圣光气还不够强大。\n");
    if((int)me->query("combat_exp")<1000000 || (int)me->query("daoxing")<700000)
    return notify_fail("以你现在的修为恐怕不行。\n");
    if((int)me->query("kee")<100 || (int)me->query("sen")<100)
    return notify_fail("以你现在的状态，不能用集气诀。\n");
    if(me->query_temp("concentrated"))
    return notify_fail("这招用太多，可就不好了。\n");
    else
{
    effect=(int)me->query_skill("segokee",1)*10;
    message_vision(HIY "$N放出圣光气，立刻形成了一个巨大的气旋，四周的自\n然力量不断集中于$N的身体之中。\n" NOR,me);
    me->add("force",effect);
    me->add("mana",effect);
    if(me->is_fighting()) me->start_busy(random(3));
    me->set_temp("concentrated",1);
    call_out("remove_effect",10,me);
}
    return 1;
}

void remove_effect(object me)
{
    if(me->query_temp("concentrated"))
      me->delete_temp("concentrated");
    else return 0;
}
