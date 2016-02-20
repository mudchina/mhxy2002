//醉字决

#include <ansi.h>

inherit SSERVER;
void check_fight(object me);
void remove_effect(object me);


int perform(object me, object target)
{
        object weapon;
        int i,j;
                        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                {if(me->query_temp("zuizj")) {remove_effect(me);return 1;}
                  else  return notify_fail("你要对谁施展「醉字决」？\n");}
        
        if(time()-(int)me->query_temp("zuizj_end") < 10) return notify_fail("再醉就醉死了！\n");

        
        if(me->query_temp("zuizj")) {remove_effect(me);return 1;}
        
            
        if(!me->is_fighting())
                return notify_fail("「醉字决」只能在战斗中使用！\n");
          
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
        
                   
        if((int)me->query_skill("yinglong-stick", 1) < 100)
                return notify_fail("你的应龙棍等级不够。\n");
        
        if((int)me->query_skill("xiantian", 1) < 100)
                return notify_fail("你的心法级别还不够，醉不了！\n");

        if((int)me->query_skill("feisheng", 1) < 100)
                return notify_fail("你的法术级别还不够，醉不了！\n");
       
        weapon=me->query_temp("weapon");
        
       
        message_vision(HIC"\n$N运起内功心法，一股酒气涌上心头，脚下踉踉跄跄，棍法若痴若颠，\n\n似醉非醉，似倒非倒，脚踏八卦，行于奇门，好一招"HIW"『醉字决』"HIC"!\n\n\n"NOR,me);
        me->set_temp("zui",0);
        me->set_temp("zuizj",1);
        me->set_temp("zuizj_time",50+random((me->query_skill("force")+me->query_skill("stick"))/8));
        
        call_out("check_fight", 1, me);
        return 1;
}


void check_fight(object me)
{
        object weapon;
        if(!me) return;        
        if( !objectp(weapon=me->query_temp("weapon")) ||
                (weapon->query("apply/skill_type") != "stick" &&
                weapon->query("skill_type") != "stick" ) || 
                me->query_skill_mapped("stick") != "yinglong-stick" ||
                me->query_skill_mapped("force") != "xiantian" ||
                me->query_skill_mapped("spells") != "feisheng" ) 
                remove_effect(me);
        else if(me->query_temp("zuizj_time")<1)
                remove_effect(me);              
        else {  me->add_temp("zuizj_time",-1);
                call_out("check_fight", 1, me);
             }
}



void remove_effect(object me)
{       if(!me) return;
        remove_call_out("check_fight");
        me->delete_temp("zuizj");
        me->delete_temp("zui");
        message_vision(HIC"$N猛一摇头，从酒醉中醒了过来。\n"NOR, me);
        me->set_temp("zuizj_end", time() );
}




