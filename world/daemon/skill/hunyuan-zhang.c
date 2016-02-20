//Cracked by Roath

// hunyuan-zhang.c »ìÔªÕÆ

inherit SKILL;

mapping *action = ({
([      "action" : "$NÒ»Ê½[37m¡¸°×ÔÆ³öá¶¡¹[2;37;0m£¬Ë«ÕÆ¼äÉýÆðÒ»ÍÅµ­µ­µÄ°×Îí£¬»º»ºÍÆÏò$nµÄ$l",
        "force" : 80,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$N²¢Ö¸Èç½££¬Ò»Ê½[1;37m¡¸°×ºç¹áÈÕ¡¹[2;37;0m£¬¼²Ïò$nµÄ$l´ÁÈ¥",
        "force" : 80,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÊ¹Ò»Ê½[1;36m¡¸ÔÆ¶ÏÇØÁë¡¹[2;37;0m£¬×óÕÆÎ¢·÷£¬ÓÒÕÆÕ§ÉìÕ§ºÏ£¬ÃÍµØ²åÍù$nµÄ$l",
        "force" : 90,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NË«ÕÆÒþÒþ·º³öÇàÆø£¬Ò»Ê½[35m¡¸ÇàËÉ´ä´ä¡¹[2;37;0m£¬»Ã³ÉÂþÌì±ÌÂÌµÄËÉÕë£¬Óêµã°ãÏò$n»÷È¥",
        "force" : 100,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÉíÐÎÍùÉÏÒ»×Ý£¬Ê¹³öÒ»Ê½[31m¡¸ÌìÉðµ¹Ðü¡¹[2;37;0m£¬Ë«ÕÆ²¢Â££¬±ÊÖ±µØÏò$nµÄ$l²åÈ¥",
        "force" : 60,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÉíÐÎÒ»±ä£¬Ê¹Ò»Ê½[1;32m¡¸ÎÞ±ßÂäÄ¾¡¹[2;37;0m£¬Ë«ÕÆ´ø×ÅÏôÉ²µÄ¾¢Æø£¬ÃÍµØ»÷Íù$nµÄ$l",
        "force" : 80,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÊ¹Ò»Ê½[1;35m¡¸¸ßÉ½Á÷Ë®¡¹[2;37;0m£¬×óÕÆÄýÖØ£¬ÓÒÕÆÇáÓ¯£¬Í¬Ê±Ïò$nµÄ$l»÷È¥",
        "force" : 120,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÍ»µØÒ»ÕÐ[1;33m¡¸½ðÓñÂúÌÃ¡¹[2;37;0m£¬Ë«ÕÆÐ®×ÅÒ»Õó·çÀ×Ö®ÊÆ£¬ÃÍµØÅüÍù$nµÄ$l",
        "force" : 100,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÒ»Ê½[35m¡¸·ç°éÁ÷ÔÆ¡¹[2;37;0m£¬Ë«ÕÆçÏÃîµØÒ»Õó»ÓÎè£¬²»¾õÒÑ»÷µ½$nµÄ$lÉÏ",
        "force" : 110,
        "damage_type" : "ðöÉË"
]),
([      "action" : "$NÒ»Ê½[1;32m¡¸ÑÌÓêÆ®Ãì¡¹[2;37;0m£¬ÉíÐÎÄýÁ¢²»¶¯£¬Ë«ÕÆÒ»¸ßÒ»µÍ£¬¿´ËÆ¼òµ¥£¬È´Áî$nÎÞ·¨¶ãÉÁ",
        "force" : 80,
        "damage_type" : "ðöÉË"
])
});

int valid_enable(string usage) { return usage=="unarmed" ; }

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int valid_learn(object me)
{
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("Á·»ìÔªÕÆ±ØÐë¿ÕÊÖ¡£\n");
        if ((int)me->query_skill("zixia-shengong", 1) < 20)
                return notify_fail("ÄãµÄ×ÏÏ¼Éñ¹¦»ðºò²»¹»£¬ÎÞ·¨Ñ§»ìÔªÕÆ¡£\n");
        if ((int)me->query("max_force") < 100)
                return notify_fail("ÄãµÄÄÚÁ¦Ì«Èõ£¬ÎÞ·¨Á·»ìÔªÕÆ¡£\n");
        return 1;
}

int practice_skill(object me)
{
        if ((int)me->query("kee") < 30)
                return notify_fail("ÄãµÄÌåÁ¦Ì«µÍÁË¡£\n");
        if ((int)me->query("force") < 40)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»Á·»ìÔªÕÆ¡£\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("shushan") +"/hunyuan-zhang/" + action;
}