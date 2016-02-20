//来去若无形 wuying.c
// write by piao 2001-10-04;
// add by xiuxiu 2002-1-18
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
void wuying_ok(object); 
inherit SSERVER; 

void remove_effect(object me, int a_amount, int d_amount);
int perform(object me, object target)
{
        object weapon,ob;
        string str;
        int skill;
        int extra;
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「"HIW"分身无影"NOR"」只能在战斗中使用。\n");
if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
              return notify_fail(" 你使用的武器不对，无法施展「"HIW"分身无影"NOR"」。\n");
        if((int)me->query("sen") < 800 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if( (int)me->query_skill("wuying", 1) < 180 )
return notify_fail("你的无影剑不够娴熟，无法施展「"HIW"分身无影"NOR"」。\n");
        if( (int)me->query("force") < 1000  ) 
                return notify_fail("你的内力不够。\n");
        if( (int)me->query("max_force") < 3000  ) 
                return notify_fail("你的内力不足，无法施展「"HIW"分身无影"NOR"」。\n");
        if((int)me->query("combat_exp") < 1000000 )
                return notify_fail("你武学经验不够，领悟不到「"HIW"分身无影"NOR"」！\n");
        if( me->query("force_factor") > 50)
                return notify_fail("「"HIW"分身无影"NOR"」绝技重招不重力。你加力太多怎能剑走轻灵？\n");
        if(me->query_temp("no_wuying"))
              return notify_fail("你刚刚使过「"HIW"分身无影"NOR"」,先歇一歇吧。\n");
        skill = me->query_skill("wuying");
        extra = me->query_skill("wuying",1) / 10;
        extra += me->query_skill("wuying",1) /10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIC "\n$N身行突变，一招"HIW"「分身无影」"HIC"瞬间犹如分出无数身影闪电般的向$n攻去！\n"NOR;
        message_vision(msg, me, target);
        me->set_temp("WYJ_perform", 1); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("WYJ_perform", 2); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("WYJ_perform", 3); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

message_vision(HIW" ┏━━┓  ┏━━┓  ┏━━┓  ┏━━┓  ┏━━┓\n"NOR,me,target); 
message_vision(HIW" ┃ "HIR"来"HIW" ┃  ┃ "HIY"去"HIW" ┃  ┃ "HIG"若"HIW" ┃  ┃ "HIB"无"HIW" ┃  ┃ "HIM"形"HIW" ┃\n"NOR,me,target); 
message_vision(HIW" ┗━━┛  ┗━━┛  ┗━━┛  ┗━━┛  ┗━━┛\n"NOR,me,target);
        me->set_temp("WYJ_perform", 4); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        me->set_temp("WYJ_perform", 5); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        if( (int)me->query_skill("wuying", 1) > 179 ){
message_vision(HIR"      来字决！\n"NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 199 ){
message_vision(HIY"            去字决！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 249 ){
message_vision(HIG"                 若字决！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 299 ){
message_vision(HIB"                        无字决！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
        if( (int)me->query_skill("wuying", 1) > 349 ){
message_vision(HIM"                           形字决！\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
}
                    if (target->query("eff_kee")<0 || !living(target))
{str=target->name()+"被"+""HIW""+me->name()+""HIM""+"用武圣门绝学『"HIW"分身无影"HIM"』杀死了。听说尸体上千疮百孔！";
        message("channel:rumor",HIM"【谣言】某人："+str+"\n"NOR,users());
                       }
        me->start_busy(3);
         me->add("force", -1000);
        me->set_temp("no_wuying",1);
        me->receive_damage("sen", 50+random(50));
        call_out("wuying_ok",5+random(3),me); 
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);

        return 1;
}
void wuying_ok(object me)
{
if (!me) return; 
      me->delete_temp("no_wuying"); 
}
