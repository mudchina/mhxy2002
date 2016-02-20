// fengbo.c  风波叉「无尽风波」

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "fork")
        return notify_fail(RED"开什么玩笑，没装备叉怎么使「碧波浪涌」？\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「碧波浪涌」只能对战斗中的对手使用。\n");
    if ((int)me->query_skill("fengbo-cha", 1) < 80 )
        return notify_fail(WHT"你风波十二叉不够娴熟，使不出「碧波浪涌」。\n"NOR);
    if(me->query_skill_mapped("force")!="dragonforce")
        return notify_fail("连龙神心法都不用，不怕被浪淹死了？\n");    
    if ((int)me->query_skill("dragonstep", 1) < 80 )
        return notify_fail(RED"你龙神身法火候不够，「碧波浪涌」不成招式。\n"NOR);
     if ((int)me->query_skill("dragonforce", 1) < 100 )
        return notify_fail(WHT"你龙神心法还不够高深，使「碧波浪涌」别走火入魔。\n"NOR);

    if ((int)me->query("max_force")<800)
        return notify_fail(RED"你的内力修为不足，无法运足「碧波浪涌」的内力。\n"NOR);
    if(me->query_temp("bibo_busy"))
        return notify_fail("你不怕海水太多淹死平民啊？\n");    
    if ((int)me->query("force")<400)
    {
        return notify_fail(HIC"你现在内力不够，没能将「碧波浪涌」使完！\n"NOR);
    }
    msg = HIC "$N作龙吟之声，踏碧波而来，$n只看到$N化做数团身影,\n"NOR;
    msg += HIC"漫天叉影席卷而来，$n奋力一架，但$N叉分数路，$n只架住一叉！\n"NOR;
    message_vision(msg, me, target);

    me->clean_up_enemy();
    target = me->select_opponent();

    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
    me->add("force", -100);
me->set_temp("bibo_busy",1);
//  me->start_busy(2+random(3));
me->start_busy(random(3));
    target->kill_ob(me);
    call_out("remove_effect",3+random(5),me);
    
    return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("bibo_busy");
}
