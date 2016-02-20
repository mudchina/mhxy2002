inherit SKILL;


mapping *action = ({
	([	"name":			"·É»¨ÂäÑà",
		"action":
"$NÊÖÖĞ$w´ó¿ª´óãØ£¬Ã¿Ò»½£Ïò$nÅüÈ¥£¬¶¼ÓĞËÆ¿ªÉ½´ó¸«Ò»°ã£¬ºÃÒ»ÕĞÊÆµÀĞÛµÄ¡¸·É»¨ÂäÑà¡¹",
		"dodge":		-15,
		"parry":		10,
		"damage":		20,
		"damage_type":		"ÅüÉË"
	]),
	([	"name":			"Ñ©»¨·ÉÌì",
		"action":
"Ö»¼û$NÉíĞÎÉÔÍË£¬ÓÒ×ãµãµØĞ±Ğ±Ô¾Æğ£¬ÊÖÖĞ$w±ÊÖ±µØÏò$nµÄ$l´ÌÈ¥\n"
"ÕıÊÇÒ»ÕĞ¡¸Ñ©»¨·ÉÌì¡¹£¡",
		"dodge":		-5,
		"parry":		-10,
		"damage":		15,
		"damage_type":		"´ÌÉË"
	]),
        ([      "name":                 "Âä»¨·ÉÑ©",
                "action":
"$N·ÉÉíÉÏÇ°£¬ÊÖÖĞ$w¼²Îè£¬Ò»ÕĞ¡¸Âä»¨·ÉÑ©¡¹»Ã³öÍÅÍÅ½£Ã¢£¬½«$n½ô½ô¹üÔÚÆäÖĞ",
		"dodge":		-10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "ÅüÉË"
        ]),
        ([      "name":                 "½£»¨×·»ê",
                "action":
"$N´òµ½ĞË·¢£¬İëµØÀïÒ»ÉùÇåĞ¥£¬ÊÖÖĞ$w³åÌì¶øÆğ£¬Ö±Ö¸$nµÄ$l£¡ÕâÕĞÉ½±Àº£Ğ¥°ãµÄ¡¸½£»¨×·»ê¡¹ÍêÈ«½«$n¾ª´ôÁË",
                "dodge":                -10,
                "parry":                -5,
                "damage":               35,
                "damage_type":          "ÅüÉË"
        ]),
        ([      "name":                 "»¨ÂäËÄ·½",
                "action":
"Ö»¼û$Nµ¥×ãµãµØ£¬Ê¹³öÒ»ÕĞ¡¸»¨ÂäËÄ·½¡¹£¬ÊÖÖĞ$w¼²½ø£¬»Ã³öµãµãº®ĞÇ£¬Ö±´Ì$nµÄ$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":               25,
                "damage_type":          "´ÌÉË"
        ]),
        ([      "name":                 "Ì«°×·É»¨",
                "action":
"$NİëÈ»Ô¾Æğ£¬Ò»Ê½¡¸Ì«°×·É»¨¡¹£¬ÉíËæ½£Æğ£¬Ïò$n±³ĞÄ¼²´ÌÊı½££¬ÕĞÕĞÊÆÈô±©·çÖèÓê£¬$nÄÄÀïÉÁ±ÜµÃ¹ı",
		"dodge":		-5,
		"parry":		-5,
		"damage":		20,
		"damage_type":		"´ÌÉË"
	]),
	([	"name":			"ÂäÓ°Éñ»¨",
		"action":
"$N×óÊÖÄó×Å½£¾ö£¬ÓÒÊÖ½£²»×¡¶¶¶¯£¬Ò»Ê½¡¸ÂäÓ°Éñ»¨¡¹£¬ÊÖÖĞ$wÆ½Æ½´Ì³ö£¬\n"
"½£¼â¼±²ü£¬¸ù±¾²»Öª¹¥ÏòºÎ´¦",
		"dodge":		-15,
		"parry":		5,
		"damage":		25,
		"damage_type":		"´ÌÉË"
	]),
	([	"name":			"»¨Æ®Íò¼Ò",
		"action":
"$NÎüÒ»¿ÚÆø£¬ÊÖÖĞÁ¬»·Æß½££¬Ò»½£¿ìËÆÒ»½££¬Ò»Ê½¡¸»¨Æ®Íò¼Ò¡¹£¬½£·¨ÇáÁéÆ®Òİ£¬Èç·çÈçÓê°ãµÄ¹¥Ïò$nµÄ$l",
		"dodge":		-5,
		"parry":		0,
		"damage":		15,
		"damage_type":		"´ÌÉË"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("ÄãµÄÄÚÁ¦ĞŞÎª²»¹»Éî£¬ÎŞ·¨Ñ§Ï°·É»¨½£·¨¡£\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»±ú½£²ÅÄÜÁ·Ï°½£·¨¡£\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("feihua-sword");

	if (dod<swo/2)
		return notify_fail("ÄãµÄÉí·¨¸ú²»ÉÏ½£·¨£¬Á·ÏÂÈ¥ºÜ¿ÉÄÜ»áÉËµ½×Ô¼º¡£\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("ÄãÌåÖÊÇ·¼Ñ£¬Ç¿Á··É»¨½£·¨ÓĞº¦ÎŞÒæ¡£\n");
	if ((int)me->query("force") < 5)
		return notify_fail("ÄãÄÚÁ¦²»×ã£¬Ç¿Á··É»¨½£·¨ÓĞ×ß»ğÈëÄ§µÄÎ£ÏÕ¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NÄ¬Ä¬»ØÒäÁËÒ»»á¶ù£¬È»ºóÁ·ÁËÒ»±é·É»¨½£·¨¡£\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

string perform_action_file(string func)
{
        return CLASS_D("yhg") + "/feihua-sword/"+func;
}
ÿÿ
