// cibei-dao.c ´È±¯µ¶
// Modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([  "action" : "$NÊÖÖĞ$wĞ±Ö¸£¬Ò»ÕĞ¡¸Í£³µÎÊÂ·¡¹£¬·´ÉíÒ»¶Ù£¬Ò»µ¶Ïò$nµÄ$lÁÃÈ¥",
    "force" : 120,
    "dodge" : -10,
    "lvl" : 0,
    "skill_name" : "Í£³µÎÊÂ·",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$NÒ»ÕĞ¡¸Í¯×Ó¹Ò»­¡¹£¬×óÓÒÍÈĞéµã£¬$wÒ»ÌáÒ»ÊÕ£¬Æ½ÈĞ»ÓÏò$nµÄ¾±²¿",
    "force" : 130,
    "dodge" : -10,
    "damage" : 5,
    "lvl" : 8,
    "skill_name" : "Í¯×Ó¹Ò»­",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$NÕ¹ÉíĞé²½£¬ÌáÑüÔ¾Âä£¬Ò»ÕĞ¡¸ÍÆ´°ÍûÔÂ¡¹£¬µ¶·æÒ»¾í£¬À¹ÑüÕ¶Ïò$n",
    "force" : 140,
    "dodge" : -5,
    "damage" : 15,
    "lvl" : 16,
    "skill_name" : "ÍÆ´°ÍûÔÂ",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$NÒ»ÕĞ¡¸¿ªÃÅ¼ûÉ½¡¹£¬$w´ó¿ª´óãØ£¬×ÔÉÏ¶øÏÂ»®³öÒ»¸ö´ó»¡£¬±ÊÖ±Åü
Ïò$n",
    "force" : 160,
    "dodge" : 5,
    "damage" : 25,
    "lvl" : 24,
    "skill_name" : "¿ªÃÅ¼ûÉ½",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$NÊÖÖĞ$wÒ»³Á£¬Ò»ÕĞ¡¸ÁÙÏª¹ÛÓã¡¹£¬Ë«ÊÖ³ÖÈĞÀ¹Ñü·´ÇĞ£¬¿³Ïò$nµÄĞØ
¿Ú",
    "force" : 180,
    "dodge" : 10,
    "damage" : 30,
    "lvl" : 33,
    "skill_name" : "ÁÙÏª¹ÛÓã",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$N»ÓÎè$w£¬Ê¹³öÒ»ÕĞ¡¸ÕÅ¹­ÍûµÄ¡¹£¬ÉÏÅüÏÂÁÃ£¬×óµ²ÓÒ¿ª£¬ÆëÆëÕÖÏò
$n",
    "force" : 210,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 42,
    "skill_name" : "ÕÅ¹­ÍûµÄ",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$NÒ»ÕĞ¡¸·çËÍÇáÖÛ¡¹£¬×ó½ÅÔ¾²½ÂäµØ£¬$wË³ÊÆÍùÇ°£¬Ğ®·çÉùÅüÏò$nµÄ
$l",
    "force" : 240,
    "dodge" : 5,
    "damage" : 50,
    "lvl" : 51,
    "skill_name" : "·çËÍÇáÖÛ",
    "damage_type" : "¸îÉË"
]),
([  "action" : "$NÅÌÉí×¤µØ£¬Ò»ÕĞ¡¸´¨Á÷²»Ï¢¡¹£¬»Ó³öÒ»Æ¬Á÷¹â°ãµÄµ¶Ó°£¬Ïò$nµÄÈ«
ÉíÓ¿È¥",
    "force" : 280,
    "dodge" : 20,
    "damage" : 60,
    "lvl" : 60,
    "skill_name" : "Í£³µÎÊÂ·",
    "damage_type" : "¸îÉË"
]),
});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»¹»Éî£¬ÎŞ·¨Ñ§Ï°´È±¯µ¶¡£\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "blade" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»°Ñµ¶²ÅÄÜÁ·Ï°´È±¯µ¶¡£\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("cibei-dao");

	if (dod<swo/2)
		return notify_fail("ÄãµÄÉí·¨¸ú²»ÉÏµ¶·¨£¬Á·ÏÂÈ¥ºÜ¿ÉÄÜ»áÉËµ½×Ô¼º¡£\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("ÄãÌåÖÊÇ·¼Ñ£¬Ç¿Á·´È±¯µ¶ÓĞº¦ÎŞÒæ¡£\n");
	if ((int)me->query("force") < 5)
		return notify_fail("ÄãÄÚÁ¦²»×ã£¬Ç¿Á·´È±¯µ¶ÓĞ×ß»ğÈëÄ§µÄÎ£ÏÕ¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NÄ¬Ä¬»ØÒäÁËÒ»»á¶ù£¬È»ºóÁ·ÁËÒ»±é´È±¯µ¶¡£\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="blade"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("bonze") + "/cibei-dao/"+func;
}
ÿÿ

