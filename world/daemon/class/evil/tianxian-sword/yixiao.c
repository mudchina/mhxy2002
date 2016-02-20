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
                return notify_fail("你想对谁用剑神一笑？\n");

        if(!me->is_fighting())
                return notify_fail("这可不是开玩笑的.\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不足了。\n");

        if((int)me->query("mana") < 1000 )
                return notify_fail("你的法力不足！\n");
        if((int)me->query("force") < 1500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("max_mana") < 1000 )
                return notify_fail("你的法力不足！\n");

        if( (int)me->query_skill("tianxian-sword", 1) < 150)
                return notify_fail("你的天仙剑法修为尚不精纯，无法施展这么厉害的武功。\n");
        if( (int)me->query_skill("evil-force", 1) < 150)
                return notify_fail("你的魔功火候不到，小心走火入魔了。\n");
        if( (int)me->query_skill("sword", 1) < 150)
                return notify_fail("你的剑法修行尚浅，还是别乱用为好。\n");

  message_vision(HIW "$N长笑一声，"+(me->query_temp("weapon"))->name()+"划出一道长虹，闪电般的击向$n！\n\n" NOR,me,target,);
       ap = (int)me->query("combat_exp");
       ap1 = 
   (int)me->query_skill("sword")+(int)me->query_skill("evil-force")+(int)me->query_skill("tianxian-sword");  
       ap2 = me->query("mana")+me->query("force") ;
       dp = (int)target->query("combat_exp");
       dp1 = target->query("mana")+target->query("force") ;
       dp2 = (int)target->query_skill("parry")+(int)target->query_skill("dodge");

       if (random(ap+dp) > dp)
   {
                message_vision(HIW "只见长空一道金虹一闪而没．．．．$n被这惊天一剑吓呆了，早已被"+(me->query_temp("weapon"))->name()+"幻出的剑芒穿体而过。\n"
NOR,me,target,);

             me->add("force",-500);
             me->add("mana",-500);
             damage=random(100+100+ap1+ap2);
             if(damage<1) damage=random(ap1);
             if(damage>1200) damage=random(1400);
             if(target->query("force")<500) {target->set("force",0);}
             else {target->add("force",-random(500));}
             target->receive_wound("kee", damage, me);
//           target->receive_wound("sen", damage, me);
//           不伤精神
             COMBAT_D->report_status(target);
             me->start_busy(random(3));

}
         else {
             message_vision(BLU "$n凭借毕生所学,终于撑过了$N的这惊天动地的一式绝学,却也是狼狈不堪。\n" NOR,me,target,);  
             COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             me->start_busy(3);
        }
        return 1;
}