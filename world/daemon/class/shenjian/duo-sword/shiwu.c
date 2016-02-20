//By tianlin@mhxy for 2001.12.4ÐÞ¸Ä
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{      
       string str;//Ò¥ÑÔµÄ±äÁ¿
	string msg;
	int extra;
       int urkee;
	object weapon;
       urkee=me->query("eff_kee");                 
	extra = me->query_skill("duo-sword",1);
	if ( extra < 210) return notify_fail("ÄãµÄ¶áÃü½£·¨»¹²»¹»´¿Êì£¡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIB"£Û¶áÃüÁ¬»·Ê®Îå½££Ý"NOR+YEL"Ö»ÄÜ¶ÔÕ½¶·ÖÐµÄ¶ÔÊÖÊ¹ÓÃ¡£\n"NOR);
	weapon = me->query_temp("weapon");
        if((int)me->query_skill("cloudforce", 1) <200)
return notify_fail("ÄãµÄÐÄ·¨»¹²»¹»´¿Êì£¡\n");
        message_vision(HIR"$NÇáÃèµ­Ð´£¬»Ó³¾ÈçÒâ£¬Ò»Ë²¼ä¾ÍÒÑÊ¹³ö¶áÃüÊ®ÈýÊ½.\nÖ»¼û$NÊÖÖÐµÄ"+ weapon->name()+ HIR "ÇáÁéÁ÷¶¯£¬¾ÍÏñÊÇºÓË®°ãµÄÏò$n´Ì³öµÚ"BLINK+HIC"Ò»"NOR+HIR"½£!\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIW"¶þ"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIC"Èý"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIB"ËÄ"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIY"Îå"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIG"Áù"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        message_vision(HIR"------>>>>>>µÚ"HIC"Æß"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIY"°Ë"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIB"¾Å"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIC"Ê®"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIW"Ê®Ò»"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIM"Ê®¶þ"HIR"½£<<<<<<------" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR"------>>>>>>µÚ"HIC"Ê®Èý"HIR"½£<<<<<<------" NOR,me,target);
        message_vision(CYN"\n$NµÄµÚÊ®Èý½£´Ì³öºó£¬ËùÓÐµÄ±ä»¯¶¼ËÆÒÑÇî¾¡£¬ÓÖÏñÊÇÁ÷Ë®ÒÑµ½¾¡Í·£¬½£ÊÆÒ²ÂýÁË£¬ºÜÂý¡£\n\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"ËäÈ»Âý£¬È´»¹ÊÇÔÚ±ä£¬$NºöÈ»Ò»½£»Ó³ö£¬²»Öø±ß¼Ê£¬²»³ÉÕÂ·¨¡£"NOR,me,target);
        message_vision(HIC"\nµ«ÊÇÕâÒ»½£È´ÏñÊÇ»­ÁúµãÇç£¬ËäÈ»¿Õ£¬È´ÊÇËùÓÐ×ª±äµÄÊàÅ¦¡£"NOR,me,target);
        message_vision(HIR"\nÈ»ºó$N¾Í´Ì³öÁË¶áÃüÊ®Èý½£µÄ"HIY"µÚ"HIB"Ê®ËÄ"HIY"½£"HIR"-------------------------------------------
\n\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
        message_vision(CYN "$NµÄÕâÒ»½£´Ì³ö£¬ËùÓÐµÄ±ä»¯ÒÑµ½ÁËÇî¾¡£¬±¾ÒÑµ½ÁË¾¡Í·µÄÁ÷Ë®£¬ÏÖÔÚ¾ÍÏñÊÇÒÑÍêÈ«¿Ý½ß¡£
$NµÄÁ¦Ò²ÒÑ½«½ßÁË¡£¿ÉÊÇ¾ÍÔÚÕâÊ±ºò£¬$NÊÖÖÐµÄ½£ºöÈ»ÓÖÆðÁËÆæÒìµÄÕð¶¯,ÌìµØÍòÎïºöÈ»È«¶¼¾²Ö¹£¬
¾ø¶Ô¾²Ö¹£¬Ã»ÓÐ±ä»¯£¬Ã»ÓÐÉú»ú!ÕâÒ»½£´øÀ´µÄ£¬Ö»ÓÐËÀ!Ö»ÓÐ"NOR+BLINK+BLU"¡¸ËÀ¡¹"NOR+CYN"£¬²ÅÊÇËùÓÐÒ»ÇÐµÄÖÕ½á£¬²ÅÊÇ
ÕæÕýµÄÖÕ½á!Á÷Ë®Ç¬¿Ý£¬±ä»¯Çî¾¡£¬ÉúÃüÖÕ½á£¬ÍòÎïÃðÍö!Õâ²ÅÊÇ"NOR+BLINK+RED"¡¸¶áÃüÊ®Èý½£¡¹"NOR+CYN"ÕæÕýµÄ¾«´â!Õâ²ÅÊÇ
ÕæÕý¶áÃüµÄÒ»½£!ÕâÒ»½£ºÕÈ»ÒÑ¾­ÊÇ"HIR"µÚ"BLINK+HIW"\tÊ®\tÎå\t"NOR+HIR"½£"NOR+CYN"£¡\n\n"NOR,me,target);
  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);   
if( (int)me->query("bellicosity",1) < 10000 )
  {  msg = HIB "ËùÓÐµÄÉúÃüºÍÁ¦Á¿£¬¶¼ÒÑ±»$NÕâÒ»½£¶áÈ¥,$nÁ³ÉÏºöÈ»Â¶³öÖÖ¿Ö¾åÖ®¼«µÄ±íÇé¡£";
msg +=  "\n$NµÄÑÛ¾¦Àï£¬ºöÈ»Ò²Â¶³öÖÖ¿Ö¾åÖ®¼«µÄ±íÇé£¬ÉõÖÁÔ¶±È$n¸ü¿Ö¾å¡£";
msg +=  "\nÈ»ºó$N¾Í×ö³ö¼þÈÎºÎÈË¶¼Ïë²»µ½£¬ÈÎºÎÈË¶¼ÎÞ·¨ÏëÏñµÄÊÂ¡£$NºöÈ»»Ø×ªÁË½£·æ£¬¸î¶ÏÁË$N×Ô¼ºµÄÑÊºí¡£\n\n"NOR;
   message_vision(msg, me, target);
	//	me->receive_wound("kee",urkee+1000);
	//	me->receive_wound("kee",50);
              target->start_busy(3);
              me->start_busy(4);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"±»"+me->name()+"ÓÃÉñ½£É½×¯¾øÕÐ[1;37m¡¸¶áÃüÊ®Îå½£¡¹[2;37;0m[1;35m¸øÉ±ËÀÁË. Ê¬ÌåÉÏÃæÎÞÊýÉËºÛ£¡";
	                message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+str+"\n"NOR,users());
	               }
       return 1;
  }
else
  {  msg = HIB "ËùÓÐµÄÉúÃüºÍÁ¦Á¿£¬¶¼ÒÑ±»$NÕâÒ»½£¶áÈ¥,$nÁ³ÉÏºöÈ»Â¶³öÖÖ¿Ö¾åÖ®¼«µÄ±íÇé¡£\n\n"NOR;
    message_vision(msg, me, target);
		target->die();
	//	me->receive_wound("kee",urkee+100);
              me->start_busy(1);
       return 1;
  }
        return 1;
}
