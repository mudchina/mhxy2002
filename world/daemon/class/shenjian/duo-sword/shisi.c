//By tianlin@mhxy for 2001.12.5
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{      
	int ap, dp;
	string msg;
	int extra;
	object weapon;                 
	extra = me->query_skill("duo-sword",1);
	if ( extra < 200) return notify_fail("你的夺命连环剑法还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIR"［夺命十四剑］"HIB"只能对战斗中的对手使用。\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <200)
return notify_fail("你的心法还不够纯熟！\n");
        message_vision(HIR"$N轻描淡写，挥尘如意，一瞬间就已使出夺命十三式，手中的"+ weapon->name()+ HIR "轻灵流动，就像是河水般的向$n刺出第"BLINK+HIC"一"NOR+HIR"剑!\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIW"二"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIC"三"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIB"四"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIY"五"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIG"六"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        message_vision(HIR"------>>>>>>第"HIC"七"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIY"八"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIB"九"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIC"十"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIW"十一"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIM"十二"HIR"剑<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>第"HIC"十三"HIR"剑<<<<<<------" NOR,me,target);
        message_vision(CYN"\n$N的第十三剑刺出后，所有的变化都似已穷尽，又像是流水已到尽头，剑势也慢了，很慢。\n\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"虽然慢，却还是在变，$N忽然一剑挥出，不著边际，不成章法。"NOR,me,target);
        message_vision(HIC"\n但是这一剑却像是画龙点晴，虽然空，却是所有转变的枢纽。" NOR,me,target);
        message_vision(HIR"\n然后$N就刺出了夺命十三剑的"HIY"第"HIB"十四"HIY"剑"HIR"-------------------------------------------
\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);            
        
        msg = RED "\n$N的剑气和杀气都很重，宛如满天岛云密布。这一剑刺出，忽然间就将满天乌云都拨开了，现出了阳光。";
msg +=  "\n这一剑刺出，所有的变化才真的已到了穷尽，本已到了尽头的流水，现在就像是已完全枯竭.\n$N的力也已竭了。\n\n" NOR; 
        if(target->query("disable_type") ==HIW "<冻僵中>" NOR)
	return notify_fail(HIY"你现在无法用夺命十四式的剑势逼迫对方！\n"NOR);
	ap = me->query_skill("sword");
	ap = ( ap * ap /100 * ap/40 ) * (int)me->query("sen") ;
	dp = target->query("combat_exp");
	if( random(ap + dp) > dp ) {
	msg +="$n被$N的剑势所迫，动弹不得！\n";
		target->set_temp("disable_inputs",1);
		target->set("disable_type",HIW "<冻僵中>" NOR);
		target->start_busy(2);
		target->set_temp("is_unconcious",1);
        	seteuid(ROOT_UID);
		target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),
		random((int)me->query_skill("sword")/30)+((int)me->query_skill("sword")/30));
	} else
		msg += "但是$n并不惧于$N的剑势。\n";

	message_vision(msg+NOR, me, target);

        me->start_busy(3);
	return 1;
}
void remove_frozen(object me)
{
   me->delete("disable_type");
   me->delete_temp("disable_inputs");
   me->delete_temp("is_unconcious");
  if(!me->is_ghost())
	message_vision(HIR "\n\n$N一声低吟，身行一顿,飞出剑光的笼罩之中！！\n\n" NOR, me);
}


