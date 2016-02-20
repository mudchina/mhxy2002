// created by ken   2001.3.9
#include <ansi.h>

inherit SSERVER;

void free(object target);
int perform(object me, object target)
{
       object weapon;
       int ap, ap1, ap2, dp, dp1, dp2, kaee, kkee, damage;
       if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你想对谁施展这一招「十万神魔」？\n");

        if(!me->is_fighting())
                return notify_fail("没事乱用什么十万神魔！\n");

        if((int)me->query("max_force") < 1500 )
                return notify_fail("你的内力还不足以发动攻势。\n");

        if((int)me->query("mana") < 1000 )
                return notify_fail("你的法力不足！\n");
        if((int)me->query("force") < 1500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("max_mana") < 1000 )
                return notify_fail("你的法力不足！\n");

        if( (int)me->query_skill("tianmo-blade", 1) < 120)
                return notify_fail("你的天魔连环八式火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("evil-force", 1) < 120)
                return notify_fail("你的魔火候不到，无法驾御这么厉害的武功。\n");
        if( (int)me->query_skill("blade", 1) < 120)
                return notify_fail("你的刀法修行尚浅，还是别乱用这招了。\n");

  message_vision(HIY+"$N祭起"+(me->query_temp("weapon"))->name()+HIY+
"聚起十万神魔之神力，顿时"+(me->query_temp("weapon"))->name()+HIR+"金光缠绕，"+
(me->query_temp("weapon"))->name()+HIY+
"魔气愈来愈盛。"+HIR+"\n\n$N狂笑一声，随手挥出魔教镇教神功“ 十-----------万----------神--------魔！”\n\n" NOR,me,target,);
       ap = (int)me->query("combat_exp");
       ap1 = 
   (int)me->query_skill("blade")+(int)me->query_skill("evil-force")+(int)me->query_skill("tianmo-blade");  
       ap2 = me->query("mana")+me->query("force") ;
       dp = (int)target->query("combat_exp");
       dp1 = target->query("mana")+target->query("force") ;
       dp2 = (int)target->query_skill("parry")+(int)target->query_skill("dodge");

       if (random(ap+dp) > dp)
   {
                message_vision( HIM 
"$N眼中金光一闪手中的"+(me->query_temp("weapon"))->name()+HIC"闪电般的绞向了$n，$n被这惊天动地之式吓破了胆，顿时被砍了个正着。\n" 
NOR,me,target,);

             me->add("force",-800);
             me->add("mana",-500);
             damage=random(100+100+ap1+ap2);
             if(damage<1) damage=random(ap1);
             if(damage>1000) damage=random(1200);
             if(target->query("force")<500) {target->set("force",0);}
             else {target->add("force",-random(500));}
             target->receive_wound("kee", damage, me);
//           target->receive_wound("sen", damage, me);
//           不伤精神
             COMBAT_D->report_status(target);
             me->start_busy(random(3));

}
         else {
             message_vision(HIW "但是$n并不慌张，从$N的头上飞了过去，躲开了这一招。\n" NOR,me,target,);  
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             me->start_busy(3);
        }
        return 1;
}
