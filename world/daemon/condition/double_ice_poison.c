//Cracked by TianLin
// double_ice_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	int damage_kee=40, damage_sen=40;

	if(me->query("max_kee")>200)
		damage_kee=me->query("max_kee")/5;
	if(me->query("max_sen")>200)
		damage_sen=me->query("max_sen")/5;
        if(damage_kee > 300) damage_kee = 300;
        if(damage_sen > 300) damage_sen = 300;
                                                	
	me->receive_wound("sen", damage_sen);
	me->receive_wound("kee", damage_kee);
	me->set_temp("death_msg","º®¶¾·¢×÷ËÀÁË¡£\n");
	me->apply_condition("double_ice_poison", duration - 1);

	if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
		message_vision("[1;36m$N×ì´½ÎÚÇà·¢ÁÁ£¬Á³É«Ê±ºìÊ±Çà£¬»ëÉí¶¶¸ö²»Í££¬²»ÖªµÀÖĞÁËÊ²Ã´Ğ°¡£\n[2;37;0m", me);
	else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
		message_vision("[35m$N×ì´½·¢Çà£¬Á³É«Ê±ºìÊ±Çà£¬Éí×ÓÎ¢Î¢·¢¶¶£¬ºÃÏñÀäµÃÀ÷º¦¡£\n[2;37;0m", me);		
	else 
		message_vision("[37m$N´òÁË¸öº®²ü¡£\n[2;37;0m", me);
		
	if( duration < 1 ) return 0;
	return 1;
}
