#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
int extra,lvl,lv;
 int i;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("万棍齐发只能在战斗中的对手使用。\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "stick" )
 return notify_fail("你手上没有棍，用个屁啊！\n");
 if( (int)me->query("force") <= 1000 )
 return notify_fail("你内力不够，不能使用万棍齐发！\n");
 extra = me->query_skill("yinglong-stick",1) / 5;
 me->add_temp("apply/attack", extra);
 me->add_temp("apply/damage", extra);
 msg = HIW  "$N一声大喝，使出武圣门绝技"HIR"万棍齐发"HIW"！手中的"+ weapon->name() +"象疯了一样向$n击来！\n" NOR;
        message_vision(msg, me, target);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
lvl=extra/10;
if(lvl>4) lvl =4;
for(i=0;i<=lvl;i++)
 {
 COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR);
}
 me->add_temp("apply/attack", -extra);
 me->add_temp("apply/damage", -extra);
 me->start_busy(2);
 return 1;
}

