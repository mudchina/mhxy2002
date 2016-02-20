//by tianlin@mhxy for 2001.8.5.

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(""HIC"¡¸ÎÞ¾¡·ç²¨¡¹"NOR"Ö»ÓÐÔÚÕ½¶·ÖÐ²ÅÄÜÊ¹ÓÃ¡£\n");

	if( (int)me->query_skill("fengbo-cha", 1) < 50 ) 
		return notify_fail("ÄãµÄÐÞÎª²»¹»Éî£¬»¹Ê¹²»³öÕâÒ»ÕÐ£¡\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"ÒÑ¾­¹»Ã¦ÁË£¬ÄãÊ¹µÄÔÙÆ¯ÁÁÒ²²»»á×¢Òâµ½¡£\n");

	message_vision(HIC"$N»ÓÕ¹¿ªÀ´£¬×óÒ»²æ£¬ÓÒÒ»²æ£¬»Ã³öÎÞÊý´óÐ¡¹â»·Ïò$nÈÆÈ¥¡£
Ëä¿´ÆðÀ´ÈáÈõÎÞÁ¦£¬È´ÍðÈôÇï²¨°ãÁ¬Ãà²»¾ø£¬ÊµÊÇ°µ²ØÉ±»ú£¡\n\n"NOR,me, target);

	mypot=(int)me->query_skill("fork");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));

	time=(int)me->query_skill("fengbo-cha", 1) /10;
	if ( time > 15 ) time = 15;
	if ( time < 5  ) time = 5;

	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIR"
 ¡¡¡¡¡¡¡¡¡¡¡¡¡¡[1;34m`-^--'`<¡¡¡¡ '¡¡¡¡¡¡¡¡ 
 ¡¡¡¡¡¡¡¡¡¡¡¡ [1;34m(_.)¡¡_¡¡)¡¡ /¡¡¡¡¡¡¡¡¡¡
 ¡¡¡¡¡¡¡¡¡¡¡¡¡¡[1;34m`.___/`¡¡¡¡/¡¡¡¡¡¡¡¡¡¡
      [2;37;0m[1;33mºÙºÙºÙ![2;37;0m   [1;34m`-----' /¡¡¡¡[2;37;0m[1;32m°¤ÉÏÁË°É£¡[2;37;0m¡¡¡¡¡¡¡¡
 ¡¡ [1;30m<------.[2;37;0m¡¡¡¡ [1;34m__ / __¡¡ \¡¡¡¡¡¡¡¡¡¡¡¡
 ¡¡ [1;30m<------l====[2;37;0m[1;34mO)))[1;30m==[2;37;0m[1;34m) \) /[1;30m====[2;37;0m¡¡¡¡¡¡¡¡
 ¡¡ [1;30m<------'[2;37;0m[1;34m¡¡¡¡`--' `.__,' \¡¡¡¡¡¡¡¡¡¡ 
 ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡[1;34ml¡¡¡¡¡¡¡¡l¡¡¡¡¡¡¡¡¡¡ 
 ¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡ [1;34m\¡¡¡¡¡¡ /[2;37;0m¡¡¡¡¡¡

"NOR+HIR"$N¹ûÈ»±»Õâ¹â»·Ì××¡£¬µ±Ê±Ä¿µÉ¿Ú´ô£¬²»ÖªËù´ë£¡\n"NOR,target);
		target->start_busy(time);
	}else {
	message_vision(HIR"²»ÁÏÈ·±»$N¿´ÆÆ£¬¹¥Æä²»±¸£¬$n·´±»´òÁË¸ö´ëÊÖ²»¼°£¡\n"NOR,target,
me);
                me->start_busy(1+random(2));
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}
