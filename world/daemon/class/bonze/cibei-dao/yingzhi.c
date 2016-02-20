#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{

        int d=me->query_skill("lotusmove",1)/2;
        int j=me->query_skill("cibei-dao", 1)/2;
     int i=me->query_skill("jienan-zhi", 1)/2;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("刀影指只能对战斗中的对手使用。\n");                

        if( (int)me->query_skill("lotusforce", 1) < 100 )
                return notify_fail("你的内功还未练成，不能使用刀影指！\n");    
        if( (int)me->query_skill("cibei-dao", 1) < 100 )
                return notify_fail("你的刀法还未练成，不能使用刀影指！\n");        
        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "cibei-dao")
                return notify_fail("你手里没有刀，无法使用刀影指！\n");
        if((int)me->query_skill("jienan-zhi", 1) < 100 )
                return notify_fail("你的指法还未练成，不能使用刀影指！\n");  
        if(me->query_skill_mapped("force") != "lotusforce")
                return notify_fail("你的内功不是莲台心法，无法使用刀影
指！\n");

                if(me->query_temp("no_yingzhi"))
                        return notify_fail("绝招滥使就不灵了！\n");
        if(me->query_skill_mapped("parry") != "cibei-dao")
           if(me->query_skill_mapped("parry") != "cibei-dao")
                return notify_fail("你的招架功夫不对，无法使用刀影指！\n");
        if((int)me->query("force") < 300 )
                return notify_fail("你现在内力不足，不能使用刀指！\n");      
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("你的基本刀法不够娴熟，不能在刀招中夹杂使用刀影指。\n");
        if((int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("你的扑技格斗不够娴熟，不能在刀招中夹杂使用刀影指。\n");     
        message_vision(HIR"\n$N大吼一声使出刀影指，指随刀走，刀光中夹杂着阵阵指风一起奔向$n！\n"NOR, me,target);
       me->add("force", -200); 
     me->add("sen", -50);
        me->add_temp("apply/dodge", d); 
  me->add_temp("apply/attack", (i+j)/1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
        me->add_temp("apply/unarmed", i/1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
     me->add_temp("apply/unarmed", -i/1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"),1);
  me->add_temp("apply/attack", -((i+j)/1)); 
   me->add_temp("apply/dodge", -d);
me->set_temp("no_yingzhi",1);
                call_out("yingzhi_ok",2+random(2),me);


        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        return 1;
}

void yingzhi_ok(object me)
{ if (!me) return;
      me->delete_temp("no_yingzhi");
}         