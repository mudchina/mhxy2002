// °ÙÄñ³¯·ï
//´óÑ©É½³°·íÎÒ¾õ×ÅÓ¦¸Ã·ÖÎªÁ½ÖÖ,Ò»ÖÖÊÇÄĞĞÔÊ¹ÓÃ,¶øÁíÒ»ÖÖÔòÊÇÅ®ĞÔÊ¹ÓÃ,ÕâÑùÒ»À´,¶ÔÒÔÇ°ÀÏÍæ¼ÒÀ´Ëµ±È½ÏºÃ,
//ÓĞµÄÀÏÍæ¼Ò·Ç³£Ï²»¶µôÉÏÏŞµÄÄÇÒ»ÖÖ³°·í,ÓĞµÄÒ²Ï²»¶²»µôÉÏÏŞµÄÄÇÒ»ÖÖ,ÎÒÏÖÔÚ¸ø¸Ä³É,ÄĞĞÔµÄµôÉÏÏŞ,Å®ĞÔ
//µÄ³°·í³¯ÉÏÒÔºóbusy´ó,ÎÒ¾õ×ÅÕâÑù¹«Æ½µã.ÎÒ¸ø°ÑÑÕÉ«×öÁËÒ»ÏÂĞŞ¸Ä,¸ÄµÄ»¹ĞĞ,»¹Çë¸ßÊÖ×öÒ»ÏÂĞŞ¸Ä¾ÍĞĞÁË.
//by tianlin 2001.5.1
/*
requirement: sword+bainiao_jian+throwing >80 ²ØÁË°µÆ÷µÄ½£ÖĞ¿É·¢°µÆ÷
                                         >150 ½£ÆøÉËÈË
damage : ·¢³ö°µÆ÷/½£Æø   1. random ·¢³ö1--10¹É
         ÃüÖĞ¼¸ÂÊ      (me->a)/(target->d)*0.3
         ÉËº¦:         ÒøÕë: 20+me->query_temp("apply/damage") 
	               ¶¾Õë: <Õ¸È±>	
                       ¿×È¸ôá: 50+me->query_temp("apply/damage") 
                       ½£Æø: me->query("force_factor")
		       ½£Æø+°µÆ÷ : ÉËº¦ÀÛ¼Ó
          ×Ô¼ºÄÚÁ¦ - me->query("force_factor")
(haven't done :P)
Ö»¼ûÄãÊÖÖĞ·çÑ©½£¼±²ü£¬»Ã³öÂúÌì½£Ã¢£¬ÎŞÊı0¼Ó×Å½£ÆøÓĞÈç°ÙÄñÍ¶ÁÖ°ãÏòĞ¡ÂÜ²·ÆËÀ´£¡
*/
//by tianlin 2001.6.6
//ÎÒ¸øĞŞ¸ÄÁËÒ»ÏÂ£¬»¹¼ÓÉÏchaofeng³örumor,ÕâÊÇÔÚÎÒÍæKOFÊ±Í»·¢ÆäÏë(snicker)!
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        string str;//¼ÓÉÏrumorµÄ±äÁ¿
        int ii,req,num_anqi,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string anqi_type,b_unit;
//added by beeby 2000.6.20
        int t;
//end add

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("ÄãÒª¶ÔË­Ê©Õ¹ÕâÒ»ÕĞ"HIY"¡¸°ÙÄñ³¯·ï¡¹"NOR"?\n");
   /*     if( (string)me->query("gender") != "Å®ĞÔ" )//±¾À´ÏëÉè³ÉÒ»¸öÊÇÄĞµÄÊ¹ÓÃµÄÒ»¸öÊÇÅ®µÄÊ¹ÓÃµÄ¡£¿ÉÊÇ¡£¡£¡£
  return notify_fail("ÕâÒ»ÕĞ°ÙÄñ³¯·ïÊÇÅ®×ÓÊ¹ÓÃµÄ,ÇëÓÃÄĞ×ÓµÄ³¯·ï¡£\n"); */
        if(!me->is_fighting())
                return notify_fail(""HIY"¡¸°ÙÄñ³¯·ï¡¹"NOR"Ö»ÄÜÔÚÕ½¶·ÖĞÊ¹ÓÃ£¡\n");

      weapon = me->query_temp("weapon");
      req=(int)me->query_skill("sword", 1)+(int)me->query_skill("bainiao-jian", 1)+(int)me->query_skill("throwing", 1); 


      if (weapon)  
        {
        if (weapon->query("anqi/allow") != 1) num_anqi=0;
        else num_anqi=weapon->query("anqi/now");
        }

      if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("°ÙÄñ³¯·ï±ØĞëÅäºÏ±ù¹ÈÄıÑª¹¦²ÅÄÜÊ¹ÓÃ¡£\n");
      if(req < 80)
            return notify_fail("Äã½£ÖĞ´ò°µÆ÷µÄ¹¦·ò»¹²»µ½»ğºò£¡\n");
      if(req < 150 && weapon->query("anqi/now") ==0)
            return notify_fail("Äã½£ÖĞÃ»ÓĞ°µÆ÷¿É´ò£¡\n");
       if (me->query("force")<200)
           return notify_fail("ÄãÄÚÁ¦²»¼Ì£¬ÄÑÒÔÓù½£·ÉÕë¡£\n");
//Added by Beeby 2000.6.20
// ¸ø°ÙÄñ½£¼ÓÉÏbusy,²»ÄÜÁ¬·¢ÁË
 	if ( ((t=(int)me->query_temp("chaofeng_time")) <= time() )
	    && (time()<t+5) )
         {  
            return notify_fail(""HIY"°ÙÄñ³¯·ç"NOR"¶àÊ¹¾Í²»ÁéÁË¡£\n");
         }
        else me->delete_temp("chaofeng_time") ;
        me->add("force", -60);

        if(num_anqi <=0) 
           { anqi_type="½£Æø"; damage=me->query("force_factor")+10; }
        else if (req < 150)
           { anqi_type=weapon->query("anqi/type"); damage=me->query_temp("apply/damage");}
        else 
           { anqi_type=weapon->query("anqi/type")+"¼Ó×Å½£Æø";
             damage=me->query_temp("apply/damage")+me->query("force_factor")+10;}
         
        msg = MAG"Ö»¼û$NÊÖÖĞ[1;33m"+weapon->query("name")+MAG"[2;37;0m[35m¼±²ü£¬»Ã³öÂúÌì½£Ã¢£¬ÎŞÊı[2;37;0m[37m"
                 +anqi_type+MAG"ÓĞÈç°ÙÄñÍ¶ÁÖ°ãÏò$nÆËÀ´£¡\n" NOR;

        if (num_anqi > 10 || num_anqi == 0) max_hit=10;
        else max_hit=weapon->query("anqi/now");
        num_hit=random(max_hit)+1;
        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;
        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp");
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}


        if (weapon->query("anqi/type")=="¿×È¸ôá") b_unit="Ö§";
        else b_unit="¸ù";
        if (weapon->query("anqi/now") != 0) remain=weapon->query("anqi/now")-num_hit;
        else remain=0;
        weapon->set("anqi/now",remain);
        if (weapon->query("anqi/now") == 0) 
          {weapon->delete("anqi/type");  weapon->set("long",weapon->query("orilong"));}
        else weapon->set("long",weapon->query("orilong")+"ÀïÃæÒÑ¾­×°ÁË"
           +chinese_number(weapon->query("anqi/now"))+b_unit+weapon->query("anqi/type")+"£¬Ïë²ğµôÓÃuninstall¡£\n"); 

        if (hitt==0)
	  {
           msg += HIW "$nÁ¬Ã¦ÉíĞĞÒ»×ª£¬Á¬ÍËÊı²½£¬ÉÁ¹ıÁËÕâÂúÌì»¨Óê°ãµÄÒ»»÷¡£\n"NOR;
           message_vision(msg, me, target);
              me->start_busy(1+random(0));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
           msg += HIG "$n¶ãÉÁ²»¼°£¬ÉíÉÏ"+chinese_number(hitt)+HIG "´¦ÖĞÁË[2;37;0m[37m"+anqi_type+"£¡\n"NOR;
           message_vision(msg, me, target);
           COMBAT_D->report_status(target); 
           if(!target->is_busy())
	       target->start_busy(8+random(8));//¼Ó´óbusy
           me->set_temp("chaofeng_time",time());
           }
        msg = HIB "$n¶Ô×Å$N¸ßÉùÂîµÀ£ººÃ°¡£¬¸Ò·Å°µÆ÷£¬¿´ÎÒÔõÃ´ÊÕÊ°Äã£¡\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);//È¥µôÕâ¸öÊ¹µÃÕâ¸ö³¯·ï¸ü¼ÓºÃÓÃ,fightÖĞÊ¹ÓÃ²»µÈÓÚÏÂkillÖ¸Áî,ÒÔÇ°µÈÓÚ.(xixi)
//By tianlin@mhxy 2001.6.6
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"±»"+me->name()+"ÓÃ"HIW"´óÑ©É½"NOR HIM"¾øÕĞ[1;37m¡¸°ÙÄñ³¯·ï¡¹[2;37;0m[1;35mÉ±ËÀÁË¡£ÉíÉÏ"BLINK HIC""+chinese_number(hitt)+""NOR HIM"´¦ÖĞÁË"HIY""+anqi_type+""NOR HIM",Ê¬ÌåºÃÏñ¸öÂí·äÎÑ£¡";
	                message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+str+"\n"NOR,users());
	               }
        return 1;
}

