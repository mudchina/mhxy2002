//lifecure.c 圣愈术
//created by foc,02-7-01
//特点说明：纯粹治愈上的效果，无攻击效果或其他防御效果。

#include <ansi.h>

int exert(object me, object target)
{
    int effect;
    if((int)me->query_skill("segokee",1)<40)
    return notify_fail("你的圣光气还不够强，无法产生治愈作用。\n");
    if((int)me->query("daoxing")<1000000)
    return notify_fail("你的修为不够。\n");
    if((int)me->query("max_force")<1000 || (int)me->query("force")<600)
    return notify_fail("你的气不足以用于治愈。\n");
    if( !target
        ||      !target->is_character()
        ||      target->is_corpse())
    return notify_fail("你要治愈谁？\n");
    if(target->is_fighting(me))
    return notify_fail("给敌人治伤？亏你想得出来！\n");
    else
    {
    effect=(int)me->query_skill("segokee",1)*2;
    message_vision(HIW "$N凝神提气，全身放出祥和的光芒，金黄色的圣光气变成了纯白色。\n$N将右手放在胸口，白色的气流缓缓地在四周流动。\n" NOR,me);
    target->receive_curing("kee",effect*10);
    target->receive_curing("sen",effect*10);
    target->add("kee",effect*30);
    target->add("sen",effect*30);
    me->add("force",-100);
    me->start_busy(2);
    tell_object (target, "你感到身体一阵轻松，说不出来的舒服。\n");
}
    return 1;
}
