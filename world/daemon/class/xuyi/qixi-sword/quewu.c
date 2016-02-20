#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon, ob;
        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");

   if((int)me->query("force") < 300 )
     return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 300 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        extra = me->query_skill("qixi-sword",1);
        if ( extra < 50) return notify_fail("你的七夕剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［七夕鹊舞］只能对战斗中的对手使用。\n");
   if (!(ob = me->query_temp("weapon"))
      || (string)ob->query("skill_type") != "sword" )
     return notify_fail("没有剑怎么能施展［七夕鹊舞］？\n"); 
if((int)me->query("bellicosity") > 150)
                return notify_fail("你的杀气太重，施展不出这美妙的招式！\n");
        weapon = me->query_temp("weapon");
         message_vision(HIY  "$N使出七夕剑法中的［七夕鹊舞］，身如飘萍随风舞，剑若流星破长空。一招连环三剑，手中的"+ weapon->name()+ HIY"闪电般向$n攻出\n第一剑！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         message_vision(HIY"第二剑！\n" NOR,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         message_vision(HIY"第三剑！\n" NOR,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->receive_damage("sen", 100);
        me->add("force", -100);
        me->start_busy(3);
        return 1;
}


