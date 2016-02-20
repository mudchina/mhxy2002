// fengyun.c  huoyun-qiang 「风云一枪」
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「风云一枪」只能对战斗中的对手使用。\n");
    if (me->query("family/family_name")!="火云洞")
        return notify_fail("你不是火云洞弟子，用不了「风云一枪」!\n");
    if( (int)me->query_skill("huoyun-qiang", 1) < 100 )
          return notify_fail(WHT"你的火云枪法不够娴熟，还使不出「风云一枪」。\n"NOR);
    if(me->query_temp("no_fengyun"))
      return notify_fail("现在没有风云可以利用!\n");      
    if( (int)me->query_skill("force", 1) < 100 )
        return notify_fail(RED"你的内功心法火候不够，使用「风云一枪」会震伤自己的经脉。\n"NOR);
    if (me->query("force")<300)
           return notify_fail("你内力不够，无法搅动风云。\n");    
    msg = HIC "$N枪尖向上一指，天边风云突起，枪挟风雷，闪电般疾刺$n。\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/2||
        random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        //me->start_busy(1);
        target->start_busy(random(4));
        damage = (int)me->query_skill("spear");
        damage = damage + random(damage);
        target->receive_damage("kee", damage,me);
        target->receive_wound("kee", damage/3,me);
        target->receive_damage("sen", damage/3,me);
        target->receive_wound("sen", damage/6,me);
        me->add("force", -damage/3);
   msg += HIR"结果这一枪穿胸而过，在$n身上开了个杯口粗的血窟窿,鲜血向后射出丈许！\n"NOR;
     message_vision(msg, me, target);
      COMBAT_D->report_status(target,1);
    } else
    {
        me->start_busy(random(3));
        msg += HIY"可是$p看破了$P的企图，闪身躲在了一边。\n"NOR;
          message_vision(msg, me, target);
    }
  
    me->set_temp("no_fengyun",1);
     call_out("remove_effect",4+random(5),me);
     if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("no_fengyun");
}
