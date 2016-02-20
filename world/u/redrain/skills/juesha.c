//write by swagger
//2001.5.10

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
int damage, def;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("盘古绝杀只能对战斗中的对手使用。\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "mace" )
 return notify_fail("你手上无锏不能使用绝杀！\n");
 if ((int)me->query_skill("pangu-mace", 1) < 120 )
 return notify_fail("你锏法不够娴熟。\n");
 if ((int)me->query_skill("yulong-force", 1) < 120 )
 return notify_fail("你的内功修为不够。\n");
 if (me->query_temp("juesha_busy")) 
 return notify_fail("你的内力消耗太大，等一会再用吧!\n");
 if( (int)me->query("force") <= 1200 )
 return notify_fail("你内力不够，使用盘古绝杀没什么威力！\n");
 msg = HIW "\n$N气运丹田，脸色变的苍白，手中"+ weapon->name() +HIW"带着呼呼风声对着$n狂扫而至！\n\n" NOR;
        message_vision(msg, me, target);
    if( random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/4)
{
msg = YEL"$n一愣，不自觉的被带了一个踉跄。" NOR;
message_vision(msg, me ,target);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
{
 msg =  HIC "$N仰天长啸，一式"HIW"『盘古绝杀』"HIC"奇快无比的向$n连续砸出三锏！\n"NOR;
        message_vision(msg, me, target);
me->set("juesha", 5);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
me->set("juesha", 6);
COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
me->set("juesha", 7);
COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
 me->delete("juesha");
 me->add("force", -200 - me->query("force_factor"));
 me->add("mana", -50);
}
}
else 
{
msg = YEL"\n$n早已经看出$N的企图，没有上当。\n" NOR;
message_vision(msg, me ,target);
 me->add("force", -200 - me->query("force_factor"));
}
 me->set_temp("juesha_busy",1);
 call_out("remove_effect",4+random(4),me);
 return 1;
}
void remove_effect(object me, object target) {
 string msg;
  if (!me) return;
  me->delete_temp("juesha_busy");
message_vision(HIB"$N的内功运转一周天，脸色又恢复了红润。\n"NOR,me);

}
