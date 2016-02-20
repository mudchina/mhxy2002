// huoyun-qiang.c ¡¾»ğÔÆÇ¹·¨¡¿


inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":
"$N´óºğÒ»Éù£¬ÊÖÖĞ$wÎ¢Ñï£¬Ò»ÕĞ[1;36m¡¸·çÆğÔÆÓ¿¡¹[2;37;0m£¬ö®Ê±Ç¹Ó°Èç·âÇ½£¬\n"
+"ÓĞÈôì»×ª¸Öµ¶°ãĞ®ÒÔÍò¾ûÖ®ÊÆ·âÏò$n",
                "damage":               30,
                "dodge":                5,
                "parry":                -10,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":
"$N·´ÉíÒ»µ¯£¬ÖØÖØÇ¹Ó°ÏÈ½«µĞÈËÉíĞÎÕÖ×¡£¬¶øºóÒ»ÕĞ[1;32m¡¸¸²Óê·­ÔÆ¡¹[2;37;0m£¬\n"
+"Ö»¼ûº®Ã¢Ò»ÉÁ£¬$w¼ºÉÁµç°ãÉäÏò$n",
                "damage":               20,
                "dodge":                15,
                "parry":                -10,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":
"$NÊ¹³ö[1;31m¡¸»ğÁúÌÚÔÆ¡¹[2;37;0m£¬ÆßµÀºìÃ¢Ò»¾­·º³öÓĞÈô²ÔÓ¥ÁÔÍÃÒÔÀ×öªÍò¾ûÖ®ÊÆ£¬"
+"¿ìÓúÆ®·çµÄ´ÌÏò$n",
                "damage":               25,
                "dodge":                20,
                "parry":                -10,
                "damage_type":  "´ÌÉË"
        ]),
         ([      "action":
"$N$wÖ¸µØ£¬ÉíĞÎ°ëÇú£¬Ê¹³öÒ»ÕĞ[1;32m¡¸Ô¡»ğ·ï»Ë¡¹[2;37;0m£¬ÍùÇ°ÉäÈ¥£¬\n"+
"Ö»¼ûÒ»µÀºìÃ¢ÂÓ¹ı£¬ÈËÇ¹ÈçÁ÷ĞÇËÆµÄ»®¹ı¿Õ¼ä£¬³åÏò$n",
                "damage":               25,
                "dodge":                -10,
                "parry":                -5,
                "damage_type":  "´ÌÉË"
        ]),
         ([      "action":
"$NÎ¢Ò»·´Éí£¬¼ºÊ¹³ö[31m¡¸Ìì»ğÁÇÔ­¡¹[2;37;0m£¬Îè³öÍò¶ä»ğ»¨£¬Ö»¼ûºì¹âÉÁÉÁ£¬\n"+
"$n±»ÕÖÈëÒ»Æ¬ºì¹âÖ®ÖĞ",
                "damage":               35,
                "dodge":                20,
                "parry":                0,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":
"$N¿ñºÈÒ»Éù£¬$w¼º·ºÆğÒ»µÀºìÃ¢£¬Ö»¼û¿ñ·ç´ó×÷£¬\n"+
"$NÇ¹ÊÆÒ»´ø£¬ÕâÕĞ[37m¡¸»ğÔÆ±ÖÈÕ¡¹[2;37;0m´İ¿İÀ­Ğà£¬»÷Ïò$n",
                "damage":               15,
                "dodge":                5,
                "parry":                -25,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":
"$N$wÒ»¶¶£¬Ç¹Ó°ÂúÌì£¬$n¶ÙÊ±±»ÕÖÔÚÕâÕĞ[35m¡¸ÍíÏ¼ÂúÌì¡¹[2;37;0mµÄÒ»Æ¬»ğ¹âÖ®ÖĞ",
                "damage":               20,
                "dodge":                15,
                "parry":                0,
                "damage_type":  "´ÌÉË"
        ]),
        ([      "action":
"$N$wÒ»¶¶£¬Ïò$n½ÅÏÂ´èÀ´£¬½ÁÆğÒ»Æ¬³¾ÍÁ£¬ÕâÕĞ[1;31m¡¸»ğÉÕÁ¬Óª¡¹[2;37;0m±ÆµÃ$nÁ¬Á¬ºóÍË£¬ÎŞ´¦Âä½Å",
                "damage":               30,
                "dodge":                10,
                "parry":                -20,
                "damage_type":  "´ÌÉË"
        ]),
             ([      "action": 
HIR"$NÊÖÖĞµÄ$w"HIR"Ö±Í¦,ÍÂÎíÕÚÈı½ç,ÅçÔÆÕÕËÄ·½,Ò»ÌìÉ±ÆøĞ×Éùºğ,ÈÕÔÂĞÇ³½²»¼û¹â¡£"NOR,
                     "damage":              100,
                      "dodge":              -40,
                      "parry":              -40,
                "damage_type":  "´ÌÉË"
        ]),
 });

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return
notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓĞ°ì·¨Á·»ğÔÆÇ¹¡£\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "spear" )
                return notify_fail("Äã±ØĞëÏÈÕÒÒ»±úÇ¹²ÅÄÜÁ·Ç¹·¨¡£\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="spear") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
            int i;
	i=me->query_temp("HYQ_perform");
	if( !me->query_temp("HYQ_perform")) {
		return action[random(7)];
	}else {
		return action[i];
	}
 
//          return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "spear" )
                return
notify_fail("Äã±ØĞëÏÈÕÒÒ»±ú³¤Ç¹»òÕßÊÇÀàËÆµÄÎäÆ÷£¬²ÅÄÜÁ·Ç¹·¨¡£\n");

        if( (int)me->query("kee") < 30 
        ||    (int)me->query("force") < 5  )
                return
notify_fail("ÄãµÄÌåÁ¦²»¹»Á·ÕâÃÅÇ¹·¨£¬»¹ÊÇÏÈĞİÏ¢ĞİÏ¢°É¡£\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("Äã°´×ÅËùÑ§Á·ÁËÒ»±é»ğÔÆÇ¹¡£\n");
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("yaomo") + "/kusong/huoyun-qiang/" + func;
}

