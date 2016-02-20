//By tianlin@mhxy for 2002.1.10

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
// #include "/u/tianlin/eff_msg.h";

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	int mydf;
	int ap, dp, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(YEL"ÄãÒª¶ÔË­Ê¹ÓÃÕâÕÐ"HIR"¡¸"HIC"Â®É½ÉýÁú°Ô"HIR"¡¹"NOR+YEL"?\n"NOR);

	mydf=(int)me->query_skill("dragonfight",1);
	if(mydf<100) 
		return notify_fail("ÄãµÄÐÞÎª²»¹»Éî£¬»¹²»ÄÜÁìÎòÉáÉí¼¼µÄ¾«Ëè¡£\n");
	mydf=(int)me->query_skill("dragonforce",1);
	if(mydf<100) 
		return notify_fail("ÄãµÄÐÞÎª²»¹»Éî£¬»¹²»ÄÜÁìÎòÉáÉí¼¼µÄ¾«Ëè¡£\n");
	
	if((int)me->query("force")<500) return
	    notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË¡£\n");

//	msg = CYN "$NÓÒÕÆ»Ó³ö£¬Õ¶Ïò$nµÄ×ó¼ç£¬\n";
	mycor=me->query_cor();
	youcps=target->query_cps();
	ob=target->query_temp("weapon");
	str="ÓÒÊÖ";
	if(objectp(ob)) str="ÊÖÖÐµÄ"+ob->query("name");
	ap=COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp/=2;	
	pp=COMBAT_D->skill_power(target,"unarmed", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=me->query_str();
	damage_bonus=mystr*(100+me->query("force_factor"))/100;

	if( random(youcps) < 15 || random(ap+dp)>dp) {
		msg  = ""HIB"$NÄ¬ÔË±Ìº£ÉñÍ¨£¬Éí·¨Ò»Õ¹£¬¾¹È»Ê¹³ö"HIC"¡¸Â®É½ÉýÁú°Ô¡¹"NOR+HIB"ÉáÉíÆËÏò$n\n\n"NOR;
		msg += "$NÉíÐÎÒ»³¤"BLINK+HIC"¡¸ÎÞµÐÁúÁú¡¹"NOR"£¬Ë«±ÛÒ»ÕóºáÉ¨£¬Ö±±Æ$nµÃÁ¬Á¬µ¹ÍË£¡\n";
		msg += ""HIB"Ö»Ìý¼û$nµÄÇ°½Å¡¸¿¦¡¹µØÒ»Éù ...\n" NOR;
              COMBAT_D->report_status(target);
              msg+="$NÉíÐÎÒ»³¤£¬³¯$nÅüÃæ¾ÍÊÇÒ»È­¡£ÕâÕÐ"HIG"¡¸²ÔÁú³öº£¡¹"NOR"ÊÆÈô±¼À×£¬ÈñÀûÎÞ±È£¡\n" NOR;
	       msg += HIB"$N¾¢Á¦Ò»ÍÂ£¬$nµÄÍ·²¿·¢³ö¡¸¿¦¡¹µØÒ»Éù±¬Ïì£¡\n";
              COMBAT_D->report_status(target);
		msg += "$NËÆÍË·´½ø£¬Í»È»ÆÛÉíÏòÇ°£¬ÎåÖ¸Èç¹³£¬Ò»ÕÐ"HIW"¡¸Ç±ÁúÎðÓÃ¡¹"NOR"£¬¶Ô×¼$nµÄÍ·²¿Ò»°Ñ×¥ÁË¹ýÈ¥£¡\n";
		msg += HIB"$N¾¢Á¦Ò»ÍÂ£¬$nµÄÍ·²¿·¢³ö¡¸¿¦¡¹µØÒ»Éù±¬Ïì£¡\n";
              COMBAT_D->report_status(target);
		message_vision(msg, me, target);
	//	msg+=COMBAT_D->report_status(target, 0);
              message_vision(HIC"$N´óºÈÒ»Éù¡ºÉýÁú¡»£¬ÈýÌõÉñÁú×Ô¾ÅÌì¶øÆð£¬Ö±·É$n£¡\n"NOR,me,target);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=me->name()+"¾¹È»Ê¹³öÁË¶«º£ÃØ´«µÄ[1;36m¡¸Â®É½ÉýÁú°Ô¡¹[2;37;0m[1;35m£¬[1;35m¿´À´ÓÖÓÐÈËËÀÔÚÕâÖÖ°ÔµÀµÄÈ­ÊõÖ®ÏÂ¡£";
	                message("channel:rumor",HIM"\n\n¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+str+"\n"NOR,users());
	               }
	} //else {
	//	msg += "¿ÉÊÇ$p¿´ÆÆÁË$PµÄÆóÍ¼£¬ÏòºóÔ½¿ª¡£\n" NOR;
	//	message_vision(msg, me, target);
	//}
	delay = random(1)+2;
	me->start_busy(delay);
	me->add("force", -300);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));

	return damage;
}


