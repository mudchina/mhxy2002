#include <ansi.h>
inherit SSERVER;
void free(object target);
int perform(object me, object target)
{
       object weapon;
 int ap, ap1, ap2, dp, dp1, dp2, kaee, kkee, ook,ap3,dp3;
       string fer;
       if( !target ) target = offensive_target(me);
       fer = me->query("id");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想对谁施展这一招「雪舞飞寒」？\n");
        if(!me->is_fighting())
                return notify_fail("「雪舞飞寒」只能在战斗中使用！\n");
  //          if((int)me->query("combat_exp") > 500000 );
  //                 return notify_fail("你的武学过高，已经无法再「雪舞飞寒」了。\n");
  //          if( (int)me->query_skill("snowsword", 1) > 100);
  //                  return notify_fail("你的风回雪舞剑法过高，「雪舞飞寒」已经无法使用。\n");
  //          if( (int)me->query_skill("sword", 1) > 100);
  //                  return notify_fail("你的基本剑法过高，「雪舞飞寒」已经无法使用。\n");
       if((int)me->query("max_force") < 600 )
               return notify_fail("你的内力修为不够！无法催动「雪舞飞寒」。\n");
       if((int)me->query("force") < 300 )
               return notify_fail("你的内力不够！\n");
        if( (int)me->query_skill("snowsword", 1) < 50)
                return notify_fail("你的风回雪舞剑法火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("sword", 1) < 50)
                return notify_fail("你的基本剑法火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("force", 1) < 50)
                return notify_fail("你的基本内功火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("moonforce", 1) < 50)
                return notify_fail("你的圆月心法火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("parry", 1) < 50)
                return notify_fail("你的拆招卸力火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("dodge", 1) < 50)
                return notify_fail("你的基本轻功火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("moondance", 1) < 50)
                return notify_fail("你的冷月凝香舞法火候不到，无法驾御这么厉害的武功。\n");
 message_vision( MAG "$N对$n妩媚的一笑,$n顿时看的呆如目鸡,这时$N挥动着手中的$w直刺$n的$1。\n\n" NOR,me,target,);
        ook = 1;
       ap = (int)me->query("combat_exp");
       ap1 = (int)me->query_skill("sword");  
       ap2 = (int)me->query_skill("snowsword");
        ap3= (int)me->query("per");
          dp = (int)target->query("combat_exp");
       dp1 = (int)target->query_skill("dodge");
       dp2 = (int)target->query_skill("parry");
        dp3= (int)target->query("per");
  (int)ap = (ap3 + ap1 * ap2) * ap;
  (int)dp = (dp3 + dp1 * dp2) * dp;
       if (random(ap) < random(dp))
       ook = 0;
       if (ook == 1)
{
                me->delete("env/brief_message");
        target->delete("env/brief_message");
  message_vision( HIC "$n正看得入迷呆在那里不知所错时，$N已经看准时机狠狠的刺了一剑。 \n" NOR,me,target,);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                message_vision( HIY "$n依然呆呆的不动，$N看准时机又是狠狠的刺了一剑。 \n" NOR,me,target,);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                message_vision( HIG "$n已恢复了正常,可是身体却依然麻木无法移动，$N趁机又向$n飞快的刺了一剑。 \n" NOR,me,target,);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                me->add("force",-150+random(50));
              me->start_busy(2+random(1));
}
         else {
                message_vision(HIR "$n看破了$N这招,并不为所动，步伐轻盈的向后跳了一步躲开了这一击。\n" NOR,me,target,);   
                me->add("force",-50+random(50));
              me->delete("env/brief_message");
        target->delete("env/brief_message");
            me->start_busy(2+random(2));
        }
        return 1;
}
