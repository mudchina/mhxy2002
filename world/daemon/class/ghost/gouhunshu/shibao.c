#include <ansi.h>

inherit F_CLEAN_UP;

int cast(object me, object target)
{      
	object *ob, where;
	int i, meskill, meforce,obskill, obforce, damage; 
	
	if( !me->is_fighting() )
		return notify_fail("你只有在战斗中才能使用尸爆术。\n");
	
	if( !target || !target->is_corpse() ) return notify_fail("你要对哪一具尸体施法？\n");
	
	if( (int)me->query("mana") < 500 ) return notify_fail("你的法力不够！\n");
	if( (int)me->query("max_mana") < 500 ) return notify_fail("你的法力不够！\n");
	if( (int)me->query("sen") < 400 ) return notify_fail("你精神不足！\n");
	
	if((int)me->query_skill("gouhunshu",1) < 50)
		return notify_fail("你的勾魂术的级别还不够!\n");
	if((int)me->query_skill("tonsillit",1) < 50)
		return notify_fail("你的摄气诀的级别还不够!\n");	

	message_vision(	HIR"$N喃喃念了几句咒语，咬破舌尖向地上的$n一喷，$n砰的一下爆裂开来！\n血水夹杂着令人窒息的尸臭四处飞溅。\n"NOR, me, target);

	destruct(target);
	me->add("mana", -(250+random(151)));
	me->receive_damage("sen", 150+random(151));
	
	where=environment(me);
	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
                if(!living(ob[i]) || ob[i]==me ) continue;
		if(!me->visible(ob[i])) continue;
             
	meskill = (me->query_skill("force")+ me->query_skill("spells"))/5;
	meforce = (me->query("max_force") + me->query("max_mana"))/5;
	obskill = (ob[i]->query_skill("force")+ ob[i]->query_skill("spells"))/50;
	obforce = (ob[i]->query("max_force") + ob[i]->query("max_mana"))/50;
             
        damage = random(meskill) + random(meforce) - random(obskill)-random(obforce);
                if( damage > 0 ) {
   ob[i]->receive_damage("kee", 10+random((me->query("max_mana")+1)/4), me);
                  tell_object(ob[i], "你被血水溅了一身，只觉得心中一阵恶心，被血水渐到的地方似乎开始溃烂了！\n");
      ob[i]->apply_condition("shibao_poison",(int)ob[i]->query_condition("shibao_poison")+10+random(21));
      COMBAT_D->report_kee_status(ob[i]);}
		if( damage <= 0) 	
		tell_object(ob[i], "你连忙向后一跳，躲开了飞溅的血水。\n");	
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);
	}
      
      me->start_busy(1+random(3));
	return 3+random(5);
}
