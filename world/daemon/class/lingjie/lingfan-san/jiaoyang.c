// link 2001.2.19
//By tianlin@mhxy for 2002.1.18¼ÓÈërumorÏµÍ³
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit SSERVER;
int perform(object me, object target)
{
        string str;
        object weapon,ob;
        int skill, damage, ap, dp, kar;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )

                return notify_fail("¡¸½¿ÑôËÆ»ğ¡¹Ö»ÄÜÔÚÕ½¶·ÖĞÊ¹ÓÃ¡£\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "umbrella")
                return notify_fail("¡¸½¿ÑôËÆ»ğ¡¹±ØĞëÓÃÉ¡²ÅÄÜÊ©Õ¹¡£\n");

        if( (int)me->query_skill("lingfan-san", 1) < 90 )
                return notify_fail("ÄãµÄ¡¸Áéá¦¾ÅÒõÉ¡¡¹²»¹»æµÊì£¬²»»áÊ¹ÓÃ¡¸½¿ÑôËÆ»ğ¡¹¡£\n");
        if( (int)me->query("force") < 600  ) 
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        if(!wizardp(me) && me->query("family/family_name")!="Áé½ç")
                return notify_fail("Äã·ÇÁé½çµÜ×Ó£¬ÎŞ·¨Ê¹ÓÃ¡¸½¾ÑôËÆ»ğ¡¹¡£\n");


        skill = me->query_skill("lingfan-san");
        weapon = me->query_temp("weapon");
        msg = MAG "$NÇåĞ¥Ò»Éù,Ê¹³ö¡¸Áéá¦¾ÅÒõÉ¡¡¹ÖĞµÄ¾ø¼¼¡¸½¿ÑôËÆ»ğ¡¹ÊÖÖĞµÄ"+weapon->name()+MAG"·èÄ§°ãµØÉ¨Ïò$n£¡\n"NOR;
        message_vision(msg, me, target);

        me->add("force", -300);

        me->clean_up_enemy();
        ob = me->select_opponent();
        damage=weapon->query("weapon_prop/damage");
        ap = me->query("combat_exp") + skill * 100 + me->query("daoxing") + me->query("con") * 1000; 
        dp = target->query("combat_exp") + target->query_skill("parry") * 100 + target->query("daoxing") 
             + target->query("kar") * 1000; 
        kar = me->query("kar");
        
        if(ap > dp) {
          msg = HIY"¡ñ½¿¡ñ£¡\n"NOR;
          message_vision(msg, me, target);
          target->add("kee", -damage);
          target->add("eff_kee", -damage/2);
          COMBAT_D->report_status(target, 0);
        }
        if(ap > dp) {
          msg = HIR"¡ñÑô¡ñ£¡\n"NOR;
          message_vision(msg, me, target);
          if(random(1) == 0) target->add("kee", -damage);
          else target->add("kee", -damage*2);
          COMBAT_D->report_status(target, 0);
          me->improve_skill("lingfan-san", 1, 1);
        }
        if(ap > dp) {
          msg = HIY"¡ñËÆ¡ñ£¡\n"NOR;
          message_vision(msg, me, target);
          if(random(5) == 0) target->add("kee", -damage);
          else target->add("kee", -damage*3);
          COMBAT_D->report_status(target, 0);
          me->improve_skill("lingfan-san", 1, 1);
        }
        if(ap > dp) {
          msg = HIR"¡ñ»ğ¡ñ£¡\n"NOR;
          message_vision(msg, me, target);
          if(random(10) == 0) target->add("kee", -damage);
          else target->add("kee", -damage*4);
          COMBAT_D->report_status(target, 0);
          me->improve_skill("lingfan-san", 1, 1);
        }
        if( me->is_fighting() ) me->start_busy(random(2)+1);
   if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"±»"+me->name()+"ÓÃÁé½ç¾øÕĞ[1;37m¡¸½¿ÑôËÆ»ğ¡¹[2;37;0m[1;35m¸øÉ±ËÀÁË. Ê¬ÌåÒÑ¾­²»¿°ÈëÄ¿£¡";
	                message("channel:rumor",HIM"¡¾Ò¥ÑÔ¡¿Ä³ÈË£º"+str+"\n"NOR,users());
	               }
        return random(3)+5;
}
