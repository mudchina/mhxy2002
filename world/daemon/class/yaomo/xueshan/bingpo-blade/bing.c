//write by swagger
//2001.5.10

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
int damage, def, extra;
 object weapon;
 if( !target ) target = offensive_target(me);
 if( !target
 || !target->is_character()
 || !me->is_fighting(target) )
  return notify_fail("寒光斩只能对战斗中的对手使用。\n");
 if(me->query("family/family_name")!="大雪山")
 return notify_fail("“寒光斩”只有雪山的才可以用！\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "blade" )
 return notify_fail("你手上无刀，不能使用寒光斩！\n");
 if ((int)me->query_skill("bingpo-blade", 1) < 100 )
 return notify_fail("你刀法不够娴熟，使不出寒光斩。\n");
 if ((int)me->query_skill("ningxie-force", 1) < 100 )
 return notify_fail("你的气功修为不够。\n");
 if (me->query_temp("xieji_busy")) 
 return notify_fail("你刚发过寒气,再用会有危险!\n");
 if( (int)me->query("force") <= 1200 )
 return notify_fail("你内力不够，使用寒光斩会有危险！\n");
 msg = HIC "\n$N一声长啸，右手一挥，顿时周围竟然变的其冷无比！
$N运起凝血神功,一团刺骨的寒气向$n直逼而来!\n" NOR;
        message_vision(msg, me, target);
    if( random((int)me->query("max_mana")*4) > (int)target->query("max_mana"))
{
{
msg = YEL"\n$n被$N发出的这团寒气包了个正着!\n\n" NOR;
message_vision(msg, me ,target);
target->start_busy(1+random(1));
 msg =  HIC "$N手中"+ weapon->name() +"寒光一闪,身形也随着腾空而起,
随即一式「寒光斩」幻出无数刀光向$n迎面劈来！\n\n"NOR;
        message_vision(msg, me, target);
 def=(int)target->query_temp("apply/armor_vs_force");
        }
    if (random(me->query("combat_exp")) > (target->query("combat_exp"))/4)
     {
     msg = HIC"$n一阵手忙脚乱，不知该如何去招架这静若水、快如电的刀法！\n"NOR;
     damage=random(800)+me->query("force_factor");
     if(damage<1)damage = 1;
     target->receive_damage("kee", damage*2, me);
     target->receive_wound("kee", damage/3, me);
     message_vision(msg, me, target);
     COMBAT_D->report_status(target);
     }
     else{
            msg = HIC"$n却心静如水，见招拆招，瓦解了$N这无声的攻势。\n"NOR;
            message_vision(msg, me, target);
        }

 me->add("force", -100);
 me->add("mana", -200);
}
else {
msg = YEL"\n$n早已经看出$N的企图，身形一闪，已避开了这团寒气。\n" NOR;
message_vision(msg, me ,target);
 me->start_busy(2+random(1));
 me->add("force", -200);
 me->add("kee", -20);
}
 me->set_temp("xieji_busy",1);
 me->start_busy(1);
 call_out("remove_effect",5+random(5),me);
 return 1;
}
void remove_effect(object me, object target) {
 string msg;
  if (!me) return;
  me->delete_temp("xieji_busy");
msg = HIR"\n过了一会,寒气渐渐的散去了。\n" NOR;
message_vision(msg, me ,target);
}

