// zhaitao.c
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
 int success_adj, damage_adj;
 success_adj = 130;
 damage_adj = 80;
 if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      target->is_corpse()
 ||      target==me)
  return notify_fail("你要对谁施展神猴摘桃？\n");
 if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
  return notify_fail("你的法力不够！\n");
 if((int)me->query("sen") < 100 )
  return notify_fail("你无法集中精力进行瞄准！\n");
 me->add("mana", -25-2*(int)me->query("mana_factor"));
 me->receive_damage("sen", 50);
 if( random(me->query("max_mana")) < 50 ) {
  write("坏了，猴子们都不知到哪儿玩耍去了！\n");
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
  "kee",
   //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
  HIC "\n$N口中念了句咒文，半空“吱吱”几声现出一群猴子，向$n又撕又咬！\n" NOR,
   //initial message
  HIR "\n结果$n躲闪不及，被猴子咬得血肉飞溅！\n" NOR,
   //success message
  HIC "\n$n连忙一侧身闪在一旁。\n" NOR,
   //fail message
  HIC "只见$n一声怒吼，猴子吓得辨不清主人，反而向$N咬去！\n" NOR,
   //backfire initial message
  HIC "结果$n躲闪不及，被猴子咬得血肉飞溅！\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
 me->start_busy(1+random(1));
 return 1+random(1);
}
