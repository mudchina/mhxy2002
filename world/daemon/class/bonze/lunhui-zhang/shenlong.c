// xian.c  ÔÆÁúÈıÏÖ
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[1;33mÉñÁúÈıÏÖÖ»ÄÜ¶ÔÕ½¶·ÖĞµÄ¶ÔÊÖÊ¹ÓÃ¡£[1;0m\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
                
        if( (int)me->query_skill("lunhui-zhang", 1) < 120 )
                return notify_fail("ÄãµÄÂÖ»ØÕÈ·¨²»¹»æµÊì£¬²»»áÊ¹ÓÃ¡¸ÉñÁúÈıÏÖ¡¹¡£\n");
                                
        if( (int)me->query_skill("lotusforce", 1) < 120 )
                return notify_fail("ÄãµÄÁ«»¨ĞÄ·¨²»¹»¸ß£¬²»ÄÜÓÃÀ´·´ÕğÉËµĞ¡£\n");
                        
        if( (int)me->query("force", 1) < 1500 )
                return notify_fail("ÄãÏÖÔÚÄÚÁ¦Ì«Èõ£¬²»ÄÜÊ¹ÓÃ¡¸ÉñÁúÈıÏÖ¡¹¡£\n");
                        
        msg = MAG "Ö»¼û$NÎ¢Î¢Ò»Ğ¦£¬ÃÍÎüÒ»¿ÚÆø,ÓûÊ¹³ö¾ÛÆøÔ¦ÕÈ¾ø¼¼¹¥»÷$n¡£\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("force")*2.2)> target->query_skill("force"))
        {
                target->start_busy(random(1));
                
                damage = (int)me->query_skill("lotusforce", 1)/2;
                damage = damage +  (int)me->query_skill("lotusmove", 1)/2;
                damage = damage +  (int)me->query_skill("lunhui-zhang", 1)/2;
                
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage*2/3);
                msg += HIY"$NÊÖÖĞìøÕÈ»Ã×÷Ò»Ìõ½ğÁú,ÌÚ¿Õ¶øÆğ,Ù¿µÄÕÖÏò$n,\n$nÖ»¾õÒ»¹É´óÁ¦ÆÌÌì¸ÇµØ°ãÑ¹À´,µÇÊ±ÑÛÇ°Ò»»¨£¬Á½¶úºäÃù,ÍÛµÄÅç³öÒ»¿ÚÏÊÑª£¡£¡\n"NOR;
                me->start_busy(2);
        } else 
        {
                msg += CYN"¿ÉÊÇ$pÃÍµØÏòÇ°Ò»Ô¾,Ìø³öÁË$PµÄ¹¥»÷·¶Î§¡£\n"NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);
        me->add("force",-200);
        return 1;
}
