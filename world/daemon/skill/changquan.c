//³¤È­ changquan.c
//menpai skill(can also be used by non-menpai NPCs)

inherit SKILL;

mapping *action = ({
        ([      "action":
"Ö»¼û$NÉíÐÎÒ»°«£¬´óºÈÉùÖÐÒ»¸ö[37m¡¸³åÌìÅÚ¡¹[2;37;0m¶Ô×¼$nµÄ±Ç×Óºô£¡µØÔÒÁË¹ýÈ¥",
                "dodge":                5,
                "parry":                5,
	    "force":		90,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "action":
"$N×óÊÖÒ»·Ö£¬ÓÒÈ­ÔËÆø£¬Ò»ÕÐ[36m¡¸°Î²ÝÑ°Éß¡¹[2;37;0m±ãÍù$nµÄ$lÕÐºô¹ýÈ¥",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "ðöÉË"
        ]),
        ([      "action":
"$NÓÒÈ­ÔÚ$nÃæÃÅÒ»»Î£¬×óÕÆÊ¹ÁË¸ö[33m¡¸Ò¶µ×ÍµÌÒ¡¹[2;37;0mÍù$nµÄ$lºÝÃüÒ»×¥",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "×¥ÉË"
        ]),
        ([      "action":
"$N²½ÂÄÒ»³Á£¬×óÈ­À­¿ª£¬ÓÒÈ­´ø·ç£¬Ò»ÕÐ[31m¡¸ºÚ»¢ÌÍÐÄ¡¹[2;37;0mÊÆ²»¿Éµ²µØ»÷Ïò$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "ðöÉË"
        ]),
        ([      "action":
"Ö»¼û$NÀ­¿ª¼ÜÊ½£¬Ò»ÕÐ[1;36m¡¸Ë«·ç¹á¶ú¡¹[2;37;0mÊ¹µÃ»¢»¢ÓÐ·ç¡£µ×ÏÂÈ´·ÉÆðÒ»½ÅÌßÏò$n$l",
                "dodge":                5,
                "parry":                5,
	    "force":		70,
                "damage_type":  "ðöÉË"
        ]),
        ([      "action":
"$N´òµÃÐËÆð£¬´óºÈÒ»Éù£º¿´ÎÒÕâÕÐ[1;32m¡¸Áú»¢Ïà½»¡¹[2;37;0m£¡\n×óÊÖÍù$nÉíºóÒ»³­£¬ÓÒÈ­±ãÍù$nÃæÃÅÔÒÁË¹ýÈ¥",
                "dodge":                5,
                "parry":                5,
	    "force":		120,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "action":
"$NÀ­¿ªºó¹­²½£¬Ë«ÕÆÊ¹ÁË¸ö[35m¡¸Èç·âËÆ±Õ¡¹[2;37;0mÍù$nµÄ$lÒ»ÍÆ",
                "dodge":                5,
                "parry":                5,
	    "force":		50,
                "damage_type":  "ðöÉË"
        ]),
        ([      "action":
"Ö»¼û$NÔË×ãÆøÁ¦£¬Ò»Á¬ÈýÈ­»÷Ïò$n$l£¬Á¦µÀÒ»È­¸ß¹ýÒ»È­£¡\nÕâÒ»ÕÐµÄÃû×Ö»¹Ïàµ±¸ßÑÅ£¬½Ð×÷[1;33m¡¸Ñô¹ØÈýµþ¡¹[2;37;0m",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "ðöÉË"
        ]),
        ([      "action":
"$NÍùºóÒ»×Ý£¬¾ÍÊÆÊ¹ÁË¸ö[1;32m¡¸ÀÏÊ÷ÅÌ¸ù¡¹[2;37;0m£¬ÓÒÍÈÉ¨Ïò$nµÄ$l",
                "dodge":                5,
                "parry":                5,
	    "force":		50,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "action":
"$NÒ»¸ö×ªÉí£¬×óÕÆ»¤ÐØ£¬ÓÒÕÆ·´ÊÖÊ¹ÁË¸ö[1;32m¡¸¶ÀÅü»ªÉ½¡¹[2;37;0mÍù$nµ±Í·Ò»Åü",
                "dodge":                5,
                "parry":                5,
	    "force":		90,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "action":
"$N·ÉÉíÔ¾Æð£¬°ë¿ÕÖÐÒ»½ÅÌßÏò$nÃæÃÅ£¬È´ÊÇ¸öÐéÕÐ¡£\nËµÊ±³ÙÄÇÊ±¿ì£¬Ö»¼û$NÒ»¸öµ¹·­£¬Ë«ÕÆÒÑµ½ÁË$nµÄ$l",
                "dodge":                5,
                "parry":                5,
	    "force":		100,
                "damage_type":  "ðöÉË"
        ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("Á·³¤È­±ØÐë¿ÕÊÖ¡£\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("ÄãµÄ¾«ÉñÎÞ·¨¼¯ÖÐÁË£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("ÄãÏÖÔÚÊÖ×ãËáÈí£¬ÐÝÏ¢Ò»ÏÂÔÙÁ·°É¡£\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»ÁË¡£\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
 return CLASS_D("fighter") + "/changquan/"+func;
}
