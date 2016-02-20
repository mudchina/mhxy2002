// By tianlin 2001.5.1
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("ÄãÏÖÔÚÃ»¿Õ£¡£¡\n");
	extra = me->query_skill("huagu-mianzhang",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("¡¸ÓÄÓÄ»ê¶Ï¡¹Ö»ÄÜÔÚÕ½¶·ÖÐÊ¹ÓÃ¡£\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("¡¸ÓÄÓÄ»ê¶Ï¡¹Ö»ÄÜ¿ÕÊÖÊ¹ÓÃ¡£\n");		
       
	 if( (int)me->query("force") < 700 )
                return notify_fail("ÄãµÄÕæÆø²»¹»£¡\n");

        if( (int)me->query_skill("force",1) < 110 )
                return notify_fail("ÄãµÄÄÚ¹¦ÐÞÎª²»¹»£¬ÎÞ·¨Ê¹ÓÃ¡¸ÓÄÓÄ»ê¶Ï¡¹£¡\n");
	
	weapon = me->query_temp("weapon");

        msg = HIW "$NÉíÐÎ»Ø×ª£¬Å­ºðÒ»Éù£¬Í¬Ê±Ê¹³ö»¯¹ÇÃàÕÆÖÐµÄ¾«Ëè£¬Ò»ÕÐ"NOR+BLINK"[1;30m¡ºÓÄÓÄ»ê¶Ï¡»"NOR+HIW"Á¬Ðø¹¥Ïò$n£¡" NOR;
        	         message_vision(msg, me, target);                
	 msg =  HIW  "²ØÀë¾÷£¡" NOR;
        message_vision(msg, me, target);
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "´Ý³¦¾÷£¡" NOR;
        message_vision(msg, me, target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "¾«Ê§¾÷£¡" NOR;
        message_vision(msg, me, target);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "Èý½¹¾÷£¡" NOR;
        message_vision(msg, me, target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "ÉË·Î¾÷£¡" NOR;
        message_vision(msg, me, target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "ËðÐÄ¾÷£¡" NOR;
        message_vision(msg, me, target);
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "Òâ»Ðã±¾÷£¡" NOR;
        message_vision(msg, me, target);
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("force", -700);
        me->start_busy(3);

        return 1;
}

