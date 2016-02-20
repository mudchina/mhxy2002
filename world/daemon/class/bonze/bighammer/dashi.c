#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mydh, hisdh,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("bighammer",1) ;
	if ( extra < 120) return notify_fail("你的[大势杖]还不够纯熟！\n");
        if(me->query("family/family_name")!="南海普陀山")
                return notify_fail("不是佛门弟子不能用「大势杖」！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［大势将至］只能对战斗中的对手使用。\n");

        if((int)me->query("force") < 500 ) return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 200 ) return notify_fail("你无法集中精力！\n");
        if((int)me->query("kee") < 200 ) return notify_fail("你气血不足！\n");
        if(me->query_temp("no_dashi")) return notify_fail("你还是休息会，等会儿再用吧！\n");
               me->add("force", -200);
             me->receive_damage("sen", 100);
             me->receive_damage("kee", 100+random(100));
	weapon = target->query_temp("weapon");
	mydh = (int)me->query("daoxing")*(int)me->query("max_mana");
	hisdh= random((int)target->query("daoxing")*((int)target->query("max_mana")+1));
	if(hisdh < mydh*4/5 )	

{
message_vision(HIR "\n$N"NOR+HIR"身形立定口诵佛号，$n"NOR+HIR"只觉得一种巨大的压力扑面而来！\n" NOR,me,target);
 if (hisdh<mydh/3)
{
message_vision(HIR "\n$n"NOR+HIR"不堪重压，身子象要爆开一般，奇痛无比！波的喷出一口鲜血！\n " NOR,me,target);
          damage=random((int)me->query("max_mana")/5);
         	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/2);
	 COMBAT_D->report_status(target);
}
           else if (hisdh<mydh/2)
{
message_vision(HIR "\n$n"NOR+HIR"暗运内力向抗，但还是喷出一口鲜血！\n " NOR,me,target);
          damage=random((int)me->query("max_mana")/10);
         	target->receive_damage("kee",damage);
            target->receive_wound("kee",damage/2);
	 COMBAT_D->report_status(target);
}
           if (weapon)
{
message_vision(HIR "\n$n"NOR+HIR"眼见大势已去，放下手中兵器" NOR, me,target);
     weapon->unequip();
	if( weapon->unequip()) weapon->move(environment(target));
}
message_vision(
HIR "\n$n"NOR+HIR"被$N"NOR+HIR"的佛法感化，跪倒在地已经忘记了自己还在战斗之中！\n\n" NOR, me,target);
            damage=3+extra/20;
            if (damage>8) damage=8;
            target->start_busy(damage);
}
else {
message_vision(
HIB "\n$n"NOR+HIR"暗运内力，逼回了这股劲风！\n" NOR, me, target);
}
        me->start_busy(2);
        me->improve_skill("bighammer", 1, 1);
        me->set_temp("no_dashi",1);
        call_out("dashi_ok",5+random(2),me);
	return 1;
}
void dashi_ok(object me)
{
if (!me) return;
me->delete_temp("no_dashi");
}