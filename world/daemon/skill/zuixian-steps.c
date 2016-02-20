// chaos-steps.c

inherit SKILL;

string *dodge_msg = ({
	"$nÒ»¸ö[1;36m¡¸×íÎÔÔÆ¶Ë¡¹[2;37;0m£¬¶ã¹ýÁË$NÕâÒ»ÕÐ¡£\n",
	"$nÉíÐÎÏòºóÒ»×Ý£¬Ê¹³öÒ»ÕÐ[1;32m¡¸Òû¾¡½­ºÓ¡¹[2;37;0m£¬±Ü¹ýÁË$NµÄ¹¥»÷¡£\n",
	"$nÊ¹³ö[37m¡¸Ç§±­²»µ¹¡¹[2;37;0m£¬Ç¡ºÃ¶ã¹ýÁË$NµÄ¹¥ÊÆ¡£\n"
       "µ«ÊÇ$nÉíÐÎÆ®ºö,Ò»ÕÐ[35m¡¸Ð¦¿´ºì³¾¡¹[2;37;0m,ÇáÇáÒ»×Ý£¬ÔçÒÑ±Ü¿ª¡£\n",
       "$nÊ¹³ö[33m¡¸ÓëÔÂ¹²Òû¡¹[2;37;0m,ÉíËæÒâ×ª£¬Ù¿µØÍùÒ»ÅÔÅ²¿ªÁËÈý³ß£¬±Ü¹ýÁËÕâÒ»ÕÐ¡£\n",
       "$nÒ»¸ö[36m¡¸×íÑÛëüëÊ¡¹[2;37;0m,ÉíÐÎÎ¢»Î£¬ÓÐ¾ªÎÞÏÕµØ±Ü¿ªÁË$NÕâÒ»ÕÐ¡£\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓÐ°ì·¨Á·×íÏÉÍûÔÂ²½¡£\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("ÄãµÄÆø»òÄÚÁ¦²»¹»£¬²»ÄÜÁ·×íÏÉÍûÔÂ²½¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}
