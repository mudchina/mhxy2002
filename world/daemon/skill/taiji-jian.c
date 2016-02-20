//[4;53m[1;31mBy tianlin@mhxy for 2001.9.30[2;37;0m

#include <ansi.h>
inherit SKILL;

mapping *action = ({
	([	"action":		"$NÊ¹Ò»ÕĞ"HIR"¡¾"NOR+HIW"Ì«¼«ÎŞÃÅ"NOR+HIR"¡¿"NOR"£¬ÊÖÖĞ$wÈçÒ»ÌõÒøÉß°ã´ÌÏò$nµÄ$l",
		"dodge":		0,
		"damage":		70,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":		"$NÊ¹³ö·âÉ½½£·¨ÖĞµÄ"HIR"¡¾"NOR+HIY"Óù½£½µÄ§"NOR+HIR"¡¿"NOR"£¬½£¹â»ô»ôÕ¶Ïò$nµÄ$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"¸îÉË"
	]),
	([	"action":		"$NÒ»ÕĞ"HIR"¡¾"NOR+HIC"°Ë·½Éñ½£"NOR+HIR"¡¿"NOR"£¬ÉíĞÎ¶¸È»»¬³öÊı³ß£¬ÊÖÖĞ$wÕ¶Ïò$nµÄ$l",
		"dodge":		0,
		"damage":		80,
		"damage_type":	"¸îÉË"
	]),
	([	"action":		"$NÊÖÖĞ$wÖĞ¹¬Ö±½ø£¬Ò»Ê½"HIR"¡¾"NOR+HIG"òßòÑµãË®"NOR+HIR"¡¿"NOR"¶Ô×¼$nµÄ$l´Ì³öÒ»½£",
		"dodge":		0,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":		"$N×İÉíÒ»Ô¾£¬ÊÖÖĞ$wÒ»ÕĞ"HIR"¡¾"NOR+HIW"½£Éí³öÇÏ"NOR+HIR"¡¿"NOR"¶Ô×¼$nµÄ$lĞ±Ğ±´Ì³öÒ»½£",
		"dodge":		0,
		"damage_type":	"´ÌÉË"
	]),
	([	"action":		"$NµÄ$wÆ¾¿ÕÒ»Ö¸£¬Ò»ÕĞ"HIR"¡¾"NOR+CYN"À´È¥ÎŞ×Ù"NOR+HIR"¡¿"NOR"´ÌÏò$nµÄ$l",
		"dodge":		0,
		"damage":		40,
		"damage_type":	"´ÌÉË"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓĞ°ì·¨Á·Ì«¼«½£·¨¡£\n");

	if( (string)me->query_skill_mapped("force")!= "wudang-force")
		return notify_fail("Ì«¼«½£·¨±ØĞëÅäºÏÎäµ±ÅÉÄÚ¹¦²ÅÄÜÁ·¡£\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØĞëÏÈÕÒÒ»°Ñ½£²ÅÄÜÁ·½£·¨¡£\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓĞ°ì·¨Á·Ï°Ì«¼«½£·¨¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("Äã°´×ÅËùÑ§Á·ÁËÒ»±éÌ«¼«½£·¨¡£\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("wudang") + "/taiji-jian/" + action;
}
