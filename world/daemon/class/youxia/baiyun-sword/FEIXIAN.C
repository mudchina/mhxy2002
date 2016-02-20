// feixian.c 叶古城的绝招 海上飘(piao)
// 天外飞仙 by piao 2001-9-11
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void feixian_ok(object); 
int perform(object me, object target)
{
        string msg;
              string str;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「"HIW"天外飞仙"NOR"」只能在战斗中使用！\n");

	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("你必须在使用兵器时才能使「"HIW"天外飞仙"NOR"」！\n");
        if(me->query("family/family_name") != "江湖浪子" )
                return notify_fail("你是哪儿偷学来的武功，也想用「"HIW"天外飞仙"NOR"」?\n");
	 if((int)me->query("force") < 1000 )
		  return notify_fail("你的内力不足！\n");
        if((int)me->query("max_force") < 2000 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("sen") < 1000 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if( me->query_skill("piaoxiang",1) < 120 )
                return notify_fail("你的血海飘香级别不够使用「"HIW"天外飞仙"NOR"」\n");
        if( me->query_skill("dodge",1) < 120 )
                return notify_fail("你的基本轻功级别不够使用「"HIW"天外飞仙"NOR"」\n");
        if( me->query_skill("baiyun-sword",1) < 120 )
                return notify_fail("你的白云剑法级别不够使用「"HIW"天外飞仙"NOR"」\n");
        if( me->query_skill("sword",1) < 120 )
                return notify_fail("你的基本剑法级别不够使用「"HIW"天外飞仙"NOR"」\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("「"HIW"天外飞仙"NOR"」需要有基本剑法的配和！\n");
	if ( (string) me->query_skill_mapped("sword") != "baiyun-sword")
        return notify_fail("「"HIW"天外飞仙"NOR"」需要有白云剑法的配和！\n");
        if(me->query_temp("no_feixian"))  //在此处设置标志位 ;
return notify_fail("你刚使用过「"HIW"天外飞仙"NOR"」，还是歇一歇吧！\n");

        extra = me->query_skill("baiyun-sword",1) / 35;
        extra += me->query_skill("sword",1) / 35;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
message_vision(HIC"\n$N脚踏"HIW"「"HIR"血海飘香"HIW"」"HIC"身法，同时使出"HIW"「"HIG"白云剑法"HIW"」"HIC"中的精髓－－"HIW"『"HIB"天外飞仙"HIW"』!\n
"HIC"            $N手中的"NOR""+ weapon->name() +""HIC"划出一道长虹，闪电般的击向$n！\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
     msg = HIY "\n只见$N手中的"NOR""+ weapon->name() +""HIY"剑光一闪，瞬间消失．．．．\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/3;i++)
	{
	msg = HIY "$N身形突转，御剑回飞！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       }
        if( (int)me->query_skill("baiyun-sword", 1) > 179 )
        {
         message_vision(HIY"\n$N身形突转，御剑回飞！\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 if (target->query("eff_kee")<0 || !living(target))  
{str=""+target->name()+""HIM""+"被"+""HIW""+me->name()+""HIM""+"用叶孤城的绝学『"HIW"天外飞仙"HIM"』杀死了！听说连尸体都没有剩下。"NOR"";
        message("channel:rumor",HIM"【"HIW"空穴来风"HIM"】某人："+str+"\n"NOR,users());
       }
}
//-----------------------------------------------------------------------------------
        if( (int)me->query_skill("baiyun-sword", 1) > 279 )
        {
message_vision(HIC"                            ┏━━━━┓\n"NOR,me,target);
message_vision(HIY"$N身形又转，御剑回飞！      "HIC"┃ "HIY"天  外"HIC" ┃\n"NOR,me,target);
message_vision(HIC"                            ┗━━━━┛\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       }
//-----------------------------------------------------------------------------------
        if( (int)me->query_skill("baiyun-sword", 1) > 379 )
        {
message_vision(HIC"                            ┏━━━━┓\n"NOR,me,target);
message_vision(HIY"$N身形又转，御剑回飞！      "HIC"┃ "HIY"飞  仙"HIC" ┃\n"NOR,me,target);
message_vision(HIC"                            ┗━━━━┛\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
       }
//-----------------------------------------------------------------------------------
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        me->set_temp("no_feixian",1); ;
        call_out("feixian_ok",10+random(5),me); ;
        me->start_busy(3+random(1));;
	return 1;
}
void feixian_ok(object me) 
{ if (!me) return; 
      me->delete_temp("no_feixian"); 
}

