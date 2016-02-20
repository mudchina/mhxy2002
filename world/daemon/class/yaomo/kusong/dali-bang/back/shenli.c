//天赐神力
//requirement:huomoforce,dali-bang all over 60

#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void remove_effect(object me, object target, int amount);
 
int perform(object me, object target)
{
        int skill_bang, skill_force, str_amount,attack_amount;

        if( !me->is_fighting() )
                return notify_fail("天赐神力只能在战斗中使用。\n");
               if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("天赐神力必须配合火魔心法才能使用。\n");
skill_force=me->query_skill("huomoforce",1);        
        if (skill_force<60) return notify_fail("你的火魔心法不够纯熟。\n");
 skill_bang=me->query_skill("dali-bang",1);
        if (skill_bang<60) 
           return notify_fail("你的棍法太差劲了。\n"); 
        if( (int)me->query("force") < 200 )      
                return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("shenli") )
                return notify_fail("你已经在运功中了。\n");
        
        me->add("force", -100);
        message_vision(
                HIW"$N哞的一声吼，一提丹田气，运力于臂，连舞了几个棍花。只见$N身边雾气越来越浓，\n手中棍越舞越快，逐渐幻做一团血雾，满堂滚动。\n" NOR, me);
 
        attack_amount=skill_bang/5;
        str_amount=(skill_bang+random(skill_force))/5; 
        me->add_temp("apply/attack", attack_amount);  
        me->add_temp("apply/strength",str_amount);    
        me->set_temp("shenli", 1);
              me->start_busy(2);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", 
           me, str_amount,attack_amount:), skill_bang/5);
 
         return 1;
}
 
void remove_effect(object me, int str_amount,int attack_amount)
{
        me->add_temp("apply/strength", -str_amount);
        me->add_temp("apply/attack", -attack_amount);
        me->delete_temp("shenli");
        message_vision(HIW"$N渐感气力不支，口中呼呼喘了几声，散去了双臂神力。\n"NOR,me);
}


