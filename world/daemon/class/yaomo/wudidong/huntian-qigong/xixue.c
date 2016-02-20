#include <ansi.h>

inherit F_CLEAN_UP;

void xixue_ok(object);

int exert(object me, object target)
{
        int meskill, obskill, meexp, obexp, mecast, obcast, damage;
object where;
 where=environment(me);
 if( where->query("no_fight") )
        return notify_fail("安全区内不能乱吸！\n");
	if( !target
        ||  !target->is_character()
        ||   target->is_corpse()
        ||   target==me)
               return notify_fail("你要吸谁的血？\n");
                
        if( (int)me->query("force") < 300 )     
                return notify_fail("你的内力不够。\n");
	if( (int)me->query("mana") < 300 )
		return notify_fail("你的法力不足。\n");
	if( (int)me->query("sen") < 100 )
		return notify_fail("你的精神不够。\n");	
	if( (int)me->query("max_force") < 300 )
		return notify_fail("你的内力不够。\n");
	if( (int)me->query("max_mana") < 300 )
		return notify_fail("你的法力不足。\n");	
 if( (int)target->query("kee") < 10 )
        return notify_fail("这个已经快被吸干了……\n"); 
	
	if( (int)me->query("food") >= (int)me->max_food_capacity() ) 	
	        return notify_fail("你吃的太饱了，再也吸不下了。\n");	
	        
	if( (int)me->query("water") >= (int)me->max_water_capacity() ) 
	        return notify_fail("你喝的太多了，再也吸不下了。\n");	       
	        
	if((int)me->query_skill("huntian-qigong",1) < 50)
		return notify_fail("你的混天气功还不够精深。\n");

        if((int)me->query_skill("yaofa",1) < 50)
		return notify_fail("你连害人的妖法都没学好，还想吸血？\n");
		
	if(me->query("family/family_name") != "陷空山无底洞")
		return notify_fail("你又不是无底洞的妖魔，吸什么血？\n");	
	
	if(me->query_temp("no_xixue"))
		return notify_fail("绝招滥使就不灵了！\n");	

        meskill =(me->query_skill("huntian-qigong",1)+me->query_skill("yaofa",1));
        obskill =(target->query_skill("force",1)+1);
        meexp =me->query("combat_exp");
        obexp =target->query("combat_exp");
        if(meexp<1000)
        mecast=1;
        else
        mecast=meexp/1000;
        if(obexp<1000)
        obcast=1;
        else
        obcast=obexp/1000;
        if((meskill-obskill)<0)
        damage=10+random(11);
        else 
        damage=random(meskill-obskill)+(meskill-obskill)*2/3;
                
        message_vision(HIG"$N阴阴的干笑了几声，张开嘴露出白森森的牙齿，突然纵身一跃，\n迅捷无比的扑向$n！\n"NOR, me,target);
        me->receive_damage("sen", 10);
     me->add("force", -100);
     me->add("mana", -200); 
        me->set_temp("no_xixue",1);
        

    if(random(meexp+5)>random(obexp)){   
        	        
        message_vision(HIR"$n躲闪不及，被$N一口咬在喉头，鲜血汩汩而出！$N吸了个不亦乐乎。\n"NOR, me,target);
        
   target->receive_damage("kee", (random(damage/2)+damage), me);
        
     if(damage<target->query("force")){
   target->add("force", -damage);}
        else{
        target->set("force", 0);}
      target->start_busy(1+random(2));
        
   if(me->query("kee")+damage*3/2 < me->query("max_kee")){
   me->add("kee", damage*2/3);}
else{
 me->set("kee", me->query("max_kee"));}
 if(me->query("eff_kee")+damage < me->query("max_kee")){
  me->add("eff_kee",damage);}
else{ me->set("eff_kee", me->query("max_kee"));}
        if(me->query("force") < me->query("max_force")){
        me->add("force", damage);}
        me->add("food", 10+random(16));
        me->add("water", 10+random(16));
  call_out("xixue_ok",4+random(3),me);
        return 1;
        }

        else{
        message_vision(HIR"$n急忙闪开，$N一下子扑了个空。\n"NOR, me,target);
     call_out("xixue_ok",2+random(2),me);
        target->kill_ob(me);
        
        return 1;}
}

void xixue_ok(object me)
{ if (!me) return;
      me->delete_temp("no_xixue");
}         
