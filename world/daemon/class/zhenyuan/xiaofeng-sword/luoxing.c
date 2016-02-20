// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int damage,dui,ap,dp,hai,ap1,dp1;
	object weapon;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［孤星落风］只能对战斗中的对手使用。\n");

   if((int)me->query_skill("xiaofeng-sword", 1) < 60 )
     return notify_fail("你的[晓风残月剑]还需要修炼」！\n");

   if((int)me->query("force") < 400)
     return notify_fail("你的内力不够，无法使用「孤星落风」！\n");

   if((int)me->query("mana") < 400)
     return notify_fail("你的法力不够，无法使用「孤星落风」！\n");

   if(me->query("family/family_name")!="五庄观")
     return notify_fail("你非五庄弟子，无法使用「孤星落风」。\n");
   
   if((int)me->query("kee") < 400 )
     return notify_fail("你体力不够，无法使用[孤星落风]！\n");

   if((int)me->query("sen") < 400 )
     return notify_fail("你精神不够，无法使用[孤星落风]！\n");

	weapon = me->query_temp("weapon");
	hai= (int)me->query("kar");

        ap=(int)(me->query_skill("sword")/10)+(int)(me->query_skill("dodge")/10)+(int)me->query("spi");
        dp=(int)(target->query_skill("parry")/10)+(int)(target->query_skill("dodge")/10);
        ap1=(int)((me->query("combat_exp")/100)*ap);
        dp1=(int)((target->query("combat_exp")/100)*dp) + 1;
   
        dui=(int)(random(ap1/dp1)*100); 

   if (dui>60) {
	msg = HIC"$N手中的"+ weapon->name() + HIC"尤如晚空落星，一道白光象闪电般挥向$n\n"NOR;
        message_vision(msg, me, target);
        damage=hai*50;
	target->receive_damage("kee",damage);
	me->receive_damage("sen",50);
        me->add("force",-150);
        me->add("mana",-150);
	me->start_busy(1+random(2));
        target->start_busy(random(2));
}
  else if(dui>40) {

	msg = HIM"$N手中的"+ weapon->name() + HIM"划过一道弧线，刺入$n的胸口..\n"NOR;
        message_vision(msg, me, target);
        damage=hai*30;
	target->receive_damage("kee",damage);
	me->receive_damage("sen",50);
        me->add("force",-150);
        me->add("mana",-150);
	me->start_busy(random(2));
        target->start_busy(random(2));
}
   else
        msg = HIB"$n两个空翻，已到丈外\n"NOR;

        message_vision(msg, me, target);
        me->start_busy(2);
        me->receive_damage("sen",100);
        me->add("mana",-100);
        me->set_temp("lx_busy",1);
        call_out("remove_effect",3+random(5),me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("lx_busy");
}