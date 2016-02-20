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
  return notify_fail("血祭只能对战斗中的对手使用。\n");
 if(me->query("family/family_name")!="陷空山无底洞")
 return notify_fail("“血祭”只有无底洞门人才可以用！\n");
 weapon = me->query_temp("weapon");
 if( (string)weapon->query("skill_type") != "blade" )
 return notify_fail("你手上无刀，不能使用血祭！\n");
 if ((int)me->query_skill("kugu-blade", 1) < 100 )
 return notify_fail("你刀法不够娴熟，使不出血祭。\n");
 if ((int)me->query_skill("huntian-qigong", 1) < 100 )
 return notify_fail("你的混天气功修为不够。\n");
 if ((int)me->query_skill("yaofa", 1) < 100 )
 return notify_fail("你的妖法修为不够。\n");
 if (me->query_temp("xieji_busy")) 
 return notify_fail("你在黑雾中还没出来呢!\n");
 if( (int)me->query("force") <= 1200 )
 return notify_fail("你内力不够，使用血祭会有危险！\n");
 extra = me->query_skill("kugu-blade",1) / 5;
// me->add_temp("apply/attack", extra);
// me->add_temp("apply/damage", extra);
 msg = HIC "\n$N念了几句咒语，右手一挥，顿时妖风四起，周围变的鬼气森森！
$N一阵阴笑，就地一躺，身体已软软的消失在一阵黑雾中。\n" NOR;
        message_vision(msg, me, target);
    if( random((int)me->query("max_mana")*4) > (int)target->query("max_mana"))
{
msg = YEL"\n$n被这阵突如其来的妖风刮的晕头转向，早已不知自己身在何处!\n\n" NOR;
message_vision(msg, me ,target);
target->start_busy(1+random(1));
 msg =  HIC "黑雾中，$N用"+ weapon->name() +"在自己身上一勒，顿时一片血雾对着$n喷涌而出！
随即一式「血祭追魂」衬着血雾，裹着刀影连续二刀向$n当头劈落！\n\n"NOR;
        message_vision(msg, me, target);
msg = HIR  ">>"+ weapon->name() +"--血光一闪"NOR"，"WHT"平平劈出一刀。
这一刀没有任何招式，其中却仿佛包含了无数的变化，虽然无招，却胜似有招！\n" NOR;
       message_vision(msg, me, target);
if (me->query_skill("parry") > random(target->query_skill("parry"))*4/5)
        {
             msg = HIC"$n还没想出该怎样拆招，一道血光已经象闪电一般，穿体而过！\n"NOR;
                damage = (int)me->query_skill("parry", 1);
                damage = damage + random(damage);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
        target->receive_damage("kee", damage-150,me);
        target->receive_wound("kee", damage*1/3, me);
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        }
     else {
            msg = HIC"$n忙一运功，往后一撤，无形中化解了这招的威力。\n"NOR;
            message_vision(msg, me, target);
        }
msg = HIR  ">>"+ weapon->name() +"--血光又闪"NOR"，"WHT"$N也由静转动。
一动便急如风，脚踏奇门，刀走奇招，式式从$n意想不到的方位奇快劈出！\n" NOR;
       message_vision(msg, me, target);
    if (random(me->query("combat_exp")) > (target->query("combat_exp"))/3)
     {
     msg = HIC"$n一阵手忙脚乱，不知该如何去招架这静若水、快如电的刀法！\n"NOR;
     damage=random(100)+me->query("force_factor");
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

//me->add_temp("apply/attack", -extra);
// me->add_temp("apply/damage", -extra);
 me->add("force", -100);
 me->add("mana", -200);
 me->add("eff_kee", -20);
}
else {
msg = YEL"\n$n早已经看出$N的企图，身形一闪，已避开了这阵妖风。\n" NOR;
message_vision(msg, me ,target);
 me->start_busy(2+random(1));
 me->add("force", -200);
 me->add("kee", -20);
}
 me->set_temp("xieji_busy",1);
 call_out("remove_effect",5+random(5),me);
 return 1;
}
void remove_effect(object me, object target) {
 string msg;
  if (!me) return;
  me->delete_temp("xieji_busy");
msg = HIR"\n妖风慢慢的散去，一个身影从黑雾中走了出来。\n" NOR;
message_vision(msg, me ,target);
}

