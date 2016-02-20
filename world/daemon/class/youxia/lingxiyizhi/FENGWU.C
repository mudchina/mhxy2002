// lingxiyizhi.c 凤舞九天
// created 17-06-2001 piao
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        string msg, str;
	int extra;
	object weapon,ob;
	if(me->is_busy())
                return notify_fail("你现在没空！无法使用「"HIR"凤舞九天"NOR"」！\n");
	extra = me->query_skill("lingxiyizhi",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「"HIR"凤舞九天"NOR"」只能在战斗中使用。\n");

        if(me->query("family/family_name") != "江湖浪子" )
                return notify_fail("你是哪儿偷学来的武功，也想用「"HIR"凤舞九天"NOR"」?\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("「"HIR"凤舞九天"NOR"」只能空手使用。\n");             
       
	 if( (int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if( (int)me->query_skill("lingxiyizhi",1) < 149 )
                return notify_fail("你的灵犀一指火候不够，无法使用「"HIR"凤舞九天"NOR"」！\n");
        if( (int)me->query_skill("unarmed",1) < 149 )
                return notify_fail("你的扑击格斗火候不够，无法领悟「"HIR"凤舞九天"NOR"」！\n");
        if( (int)me->query_skill("force",1) < 179 )
                return notify_fail("你的内功修为不够，无法使用「"HIR"凤舞九天"NOR"」！\n");
      me->add_temp("apply/attack",extra*1);
        me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

        msg = HIW "$N灵犀一指，浑然之中使出了"HIR"「凤舞九天」"HIW"顿时天地间仿佛出现一只凤凰飞向$n！
"HIR"凤                                                                  凤
      舞                                                      舞
            九                                          九
                  天                              天\n" NOR;
	         message_vision(msg, me, target);                
        msg = HIY  "\n          凤\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "\n                   舞\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "\n                            九\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "\n                                     天\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

                  if (target->query("eff_kee")<0 || !living(target))  
{str=""+target->name()+"被"+""HIW""+me->name()+""HIM""+"用陆小凤的绝学『"HIR"凤舞九天"HIM"』杀死了！听说瞬间尸体一化为灰烬。"NOR"";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());
	               }

        me->add_temp("apply/attack",-extra*2);
	 me->add_temp("apply/damage",-extra*2);
        me->receive_damage("kee", 100);
        me->receive_damage("sen", 200);
        me->add("force", -400);
    me->start_busy(2+random(2));;

        return 1;
}

