#include <ansi.h> 
#include <combat.h> 
inherit SSERVER; 
void wusi_ok(object); 
int perform(object me, object target) 
{ 
        object weapon; 
                 
        if( !target ) target = offensive_target(me); 

        if( !target 
        ||      !target->is_character() 
        ||      target->is_corpse() 
        ||      target==me) 
return notify_fail("你要对谁施展这一招「无私无敌」？\n"); 

        if(!me->is_fighting()) 
return notify_fail("「无私无敌」只能在战斗中使用！\n"); 
if((string)me->query("family/family_name") != "将军府" )
return notify_fail("你非久居官场，怎懂得无私无畏的含意？\n");

 if((int)me->query("max_force") < 300 ) 
                return notify_fail("你的内力不够！\n"); 

if((int)me->query_skill("wusi-mace", 1) < 60) 
return notify_fail("你的无私锏法级别还不够，使用这一招会有困难！\n"); 

if(me->query_temp("no_wusi"))
return notify_fail("绝招使多了就不灵了！"); 
        me->delete("env/brief_message"); 
target->delete("env/brief_message"); 

message_vision(HIY"\n$N一声虎吼：行军治国，天下为公！一种前所未有的压迫向$n逼来。\n"NOR,me,target); 

me->set_temp("WSM_perform", 8); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

me->delete_temp("WSM_perform"); 

        me->add("force", -100); 
me->set_temp("no_wusi",1); 
call_out("wusi_ok",2+random(4),me); 


        if( !target->is_fighting(me) ) { 
                if( living(target) ) { 
                        if( userp(target) ) target->fight_ob(me); 
                        else target->kill_ob(me); 
                } 
        } 

        return 1; 
} 

void wusi_ok(object me) 
{ if (!me) return; 
 me->delete_temp("no_wusi"); 
}          

