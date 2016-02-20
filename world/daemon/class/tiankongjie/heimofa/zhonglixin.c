// zhenyan.c
#include <ansi.h>
//#define SPELL_D "/adm/daemons/spelld"
inherit SSERVER;
int cast(object me, object target)
{
 int success_adj, damage_adj;
 success_adj = 130;
 damage_adj = 150;
 if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      target->is_corpse()
 ||      target==me)
  return notify_fail("你要对谁引动重力心？\n");
 if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
  return notify_fail("你的法力不够！\n");
 if((int)me->query("sen") < 20 )
  return notify_fail("你无法集中精力引动重力心。\n");
 me->add("mana", -25-2*(int)me->query("mana_factor"));
 me->receive_damage("sen", 10);
 if( random(me->query("max_mana")) < 50 ) {
  write("好象没反应，再来一次吧！\n");
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
  HIC "$N从地面升起，双手托天，黑光飘渺！
"HIB"$N口中厉声尖啸：“"NOR""WHT"重力心，"HIW"须弥山"NOR""WHT"！！！"HIB"”
"NOR"　"WHT"一座巨大的"WHT"　"HIW"须弥山"NOR"　"WHT"被一团黑气裹着砸向$n\n" NOR,
   //initial message
  RED "结果$n被压扁了！\n" NOR,
   //success message
  HIR "$n一见不妙，纵身向前一跃，避了开去。\n" NOR,
   //fail message
  HIW "$n几个小跳站到$N的身下。须弥山　落在$N的头顶。\n" NOR,
   //backfire initial message
  RED "结果$N被压扁了！\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
 me->start_busy(1+random(2));
 return 3+random(5);
}

