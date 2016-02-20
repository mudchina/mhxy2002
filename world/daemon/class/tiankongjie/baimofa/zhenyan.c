// zhenyan.c
#include <ansi.h>
//#define SPELL_D "/adm/daemons/spelld"
inherit SSERVER;
int cast(object me, object target)
{
 int success_adj, damage_adj;
 success_adj = 150;
 damage_adj = 120;
 if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      target->is_corpse()
 ||      target==me)
  return notify_fail("你要对谁念动真言？\n");
 if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
  return notify_fail("你的法力不够！\n");
 if((int)me->query("sen") < 20 )
  return notify_fail("你无法集中精力念动真言。\n");
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
  HIC "$N右手食指点住拇指指尖，后三指并拢，翻掌向外。
"MAG"口中喃喃念动“"HIR"哆，"HIY"摩，"YEL"唏，"HIG"哆，"HIC"兹，"HIB"咔"HIM"啦"HIW"哒！！”
"NOR"　"WHT"只见一道气流快速卷向$n。\n" NOR,
   //initial message
  MAG "结果气流卷住了$n,$n快要被撕裂了。\n" NOR,
   //success message
  HIR "$n一见不妙，飞身后纵，避了开去。\n" NOR,
   //fail message
  HIW "$n一个侧身让过气流前端锐气，又一个旋身，反将气流引向了$N！\n" NOR,
   //backfire initial message
  HIR "结果$N被气流冲向乐天空！\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
 me->start_busy(1+random(2));
 return 3+random(5);
}

