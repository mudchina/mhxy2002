//·ç²¨Ê®¶þ²æ fengbo-cha.c
//9-17-97 pickle
//by tianlin 2001/5/1

/*
·ç²¨Ê®¶þ²æ    dodge  0    parry  -5    damage  25
ÒòÆäÓÐÌØ±ðÖ®´¦£¬½¨Òé¸÷ÏîÔÝÉèÎªÖÐµÈ¡£
*/

//pickle, not changed yet, please try to be compatible. 

// ÎôÈËÒÑ³Ë»Æº×È¥£¬´ËµØ¿ÕÓà»Æº×Â¥
// »Æº×Ò»È¥²»¸´·µ£¬°×ÔÆÇ§ÔØ¿ÕÓÆÓÆ
// Çç´¨Á¤Á¤ººÑôÊ÷£¬·¼²ÝÆàÆàðÐðÄÖÞ
// ÈÕÄºÏç¹ØºÎ´¦È¥£¬ÑÌ²¨½­ÉÏÊ¹ÈË³î

// ½­ÉÏÍùÀ´ÈË£¬µ«°®öÔÓãÃÀ
// ¾ý¿´Ò»Ò¶ÖÛ£¬³öÃ»·ç²¨Àï

inherit SKILL;

mapping *action = ({
        ([      "name":                 "¡¸ÎôÈËÒÑ³Ë»Æº×È¥¡¹",
                "action":
"$NËÆºõÔÚÑ°ÕÒÐ©Ê²Ã´£¬ÊÖÖÐ$wÔÚÉíÇ°ÊÔÌ½ÁËÊý²æ¡£\n"
"²æ¼âËùÖ¸Ö®´¦£¬ÕýÊÇ$nµÄ$l£¬Ô­À´ÊÇ[1;33m¡¸ÎôÈËÒÑ³Ë»Æº×È¥¡¹[2;37;0m",
                "dodge":                0,
		"parry":		0,
                "damage":               25,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$n»Ó¶¯$W£¬ÔÚÉíÇ°»­ÁË¸ö°ëÔ²£¬ÕýºÃµ²¿ª$NµÄ¹¥ÊÆ¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸´ËµØ¿ÕÓà»Æº×Â¥¡¹",
                "action":
"$NÉíÐÎ²»¶¯£¬ÊÖÖÐ$wÓÃÒ»ÕÐ[35m¡¸´ËµØ¿ÕÓà»Æº×Â¥¡¹[2;37;0m£¬\n"
"ÅÄÏò$nµÄ$l¡£ÕâÕÐËÆºõÆÄÎªÖÏÖÍÉúÓ²£¬µ«ºÁ²»ÍÏÄà´øË®£¬¹¥ÊÆÉõÊÇÁèÀ÷",
                "dodge":                0,
		"parry":		0,
                "damage":               25,
                "damage_type":  	"ðöÉË",
		"parry_msg":
"$nË¿ºÁ²»ÎªËù¶¯£¬ÇáÃèµ­Ð´µØ»Ó²æÒ»´Ì£¬±ÆµÃ$N»ØÊÖ×Ô·À¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸»Æº×Ò»È¥²»¸´·µ¡¹",
                "action":
"$N½ÓÁ¬¼¸¸öÆðÂä£¬×÷ÊÆÓû×ß£¬$nÃ¦¼²×·²»µü¡£ÕýÔÚÕâÊ±£¬\n"
"$NÓÚ¿ÕÖÐÍ»È»»ØÉí£¬Ò»Ê½[1;32m¡¸»Æº×Ò»È¥²»¸´·µ¡¹[2;37;0mÖ±Ö¸$nµÄ$l",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"´ÌÉË",
		"parry_msg":
"$nÒ»¶¶ÊÖÖÐ$W£¬ÔÚ$N±øÆ÷ÉÏÒ»°´£¬½èÊÆ×Ý¿ªÊýÕÉ¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸°×ÔÆÇ§ÔØ¿ÕÓÆÓÆ¡¹",
                "action":
"$NÒ»ÉùÇåÐ¥£¬µ«¼ûÂþÌì²æÓ°£¬»¯×÷¶ä¶ä°×ÔÆ£¬ÈÅµÃ$nÑÛ»¨çÔÂÒ\n"
"ÕâÕÐ[1;37m¡¸°×ÔÆÇ§ÔØ¿ÕÓÆÓÆ¡¹[2;37;0mÆÄÎª´«Éñ£¬¹ûÈ»ÓÐÒ»·¬Ç°²»¼û¹ÅÈË£¬ºó²»¼ûÀ´ÕßµÄÆø¸Å",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"ðöÉË",
		"parry_msg":
"$n½«$WÎèµÃ·çÓê²»Í¸£¬$NÎÞÄÎÖ®ÏÂÖ»ºÃ»»ÕÐ¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸Çç´¨Á¤Á¤ººÑôÊ÷¡¹",
                "action":
"$NÊÖÖÐ$wÒ»²ü£¬ÓÃÒ»ÕÐ[1;32m¡¸Çç´¨Á¤Á¤ººÑôÊ÷¡¹[2;37;0m£¬Ñ¸½ÝÎÞ±ÈµØÔÚ$nÉÏÏÂ×óÓÒ¸÷´ÌÒ»²æ",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"´ÌÉË",
		"parry_msg":
"$nÒÔÊÖÖÐ$W»­ÁË¸öÔ²»¡£¬½«ÖÜÉíÆÆÕÀ¶¼·âËÀÁË¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸·¼²ÝÆàÆàðÐðÄÖÞ¡¹",
                "action":
"$NÊ©³öÒ»ÕÐ[33m¡¸·¼²ÝÆàÆàðÐðÄÖÞ¡¹[2;37;0m£¬Ö»¼û$wÈôÓÐÈôÎÞµØÒ»Ì½£¬\n"
"¿´È¥ÊÆËÆºõ´ÌÏò$n×ó²àÊý´ç´¦£¬µ«²»ÖªÔõµÄ£¬×ªË²¼ä²æ¼âÒÑµ½ÁË$l",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$nÇÓÉúÉúµØ¾Ù²æÒ»µ²£¬ËÆºõÁ¦²»´ÓÐÄ¡£µ«µÈµ½¶þÈË±øÈÐÏà½»Ê±£¬\n"
"$n$WÉÏºöÈ»·¢³öÒ»¹ÉÈÍÁ¦£¬½«$Nµ²ÁË¿ªÈ¥¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸ÈÕÄºÏç¹ØºÎ´¦È¥¡¹",
                "action":
"$NÀÊÐ¦Ò»Éù£¬ÊÖÖÐ$w·º³öÖØÖØ°µÓ°£¬ºÃËÆÒ»ÕóÕóÅ¨Îí£¬ÍÆÏò$n¡£\n"
"$n¿´²»Í¸ÕâÕÐ[36m¡¸ÈÕÄºÏç¹ØºÎ´¦È¥¡¹[2;37;0mµÄÀ´Â·£¬ÊµÔÚ²»ÖªÈçºÎÕÐ¼Ü",
                "dodge":                0,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"´ÌÉË",
		"parry_msg":
"$n²»±Ü²»ÈÃ£¬Í¦$WÔÚÉíÇ°¿Õ´¦Á¬´ÎÊý²æ¡£ÕâÕÐ¿´À´Æ½Æ½ÎÞÆæ£¬È´ÓÚÆ½µ­ÖÐ½«$NµÄ¹¥ÊÆ·âËÀÁË¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸ÑÌ²¨½­ÉÏÊ¹ÈË³î¡¹",
                "action":
"$n¸Õ´­µÃÒ»´­£¬È´¼û$NÉíÐÎÒ»ÉÁ£¬ÒÑ¾­×ÙÓ°È«ÎÞ¡£$n»¹Î´À´µÃ¼°×ªÉí£¬\n"
"$NµÄ$wÒÑµ½±³ºóÁË¡£ÕâÕÐ[1;33m¡¸ÑÌ²¨½­ÉÏÊ¹ÈË³î¡¹[2;37;0m¹ûÈ»Çá¿ìÎÞ±È£¬ÁîÈË·À²»Ê¤·À",
                "dodge":                -10,
		"parry":		-10,
                "damage":               25,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$nÑÛ¼û$N¹¥ÊÆÁèÀ÷£¬Ã¦ÓÃÒ»ÕÐ[1;33m¡¸ÑÌ²¨½­ÉÏÊ¹ÈË³î¡¹[2;37;0m£¬Á¬×ªÊýÈ¦£¬½«$NµÄÁ¦²¦ÔÚÒ»±ß¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸½­ÉÏÍùÀ´ÈË¡¹",
                "action":
"$NÅ­ß³Ò»Éù£¬ÊÖÖÐ$wÆë¿ìÎÞ±ÈµØÔÚ$nÉíÇ°À´À´»Ø»ØÁ¬»®Æß»®¡£\n"
"ÕâÕÐ[33m¡¸½­ÉÏÍùÀ´ÈË¡¹[2;37;0m±ä»ÃÎÞ·½£¬$nÊµÔÚ²»ÖªÄÄÕÐÊÇÐé£¬ÄÄÕÐÊÇÊµ",
                "dodge":                5,
		"parry":		-15,
                "damage":               30,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$nÁ¬»ÓÊÖÖÐ$W£¬Ö»Ìý¶£¶£µ±µ±Ò»ÕóÃÜÏì£¬ÖÕÓÚ½«$Nµ²ÁË»ØÈ¥¡£\n",
		"parry_power":		15,
        ]),
        ([      "name":                 "¡¸µ«°®öÔÓãÃÀ¡¹",
                "action":
"$NÊÖÖÐ$w»º»º»­ÁË¸öÔ²È¦£¬ÓÃÒ»ÕÐ[31m¡¸µ«°®öÔÓãÃÀ¡¹[2;37;0mÂýÂýÏò$nµÄ$lÌ×È¥",
                "dodge":                5,
		"parry":		-5,
                "damage":               35,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$nËÆºõÐØÓÐ³ÉÖñ£¬Í¦²æÁ¬»®Êý¸öÔ²È¦¡£$N¿´²»Í¸$nµÄÊØÊÆ£¬¹ûÈ»²»¸ÒÃ³È»½ø¹¥¡£\n",
		"parry_power":		0,
        ]),
        ([      "name":                 "¡¸¾ý¿´Ò»Ò¶ÖÛ¡¹",
                "action":
"$NÉíÐÎÒ»Ðý£¬³åÌì¶øÆð¡£ÊÖÖÐ$w½è×ÅÏÂ³åÖ®ÊÆ£¬Ò»ÕÐ[1;36m¡¸¾ý¿´Ò»Ò¶ÖÛ¡¹[2;37;0mÖ±²å$nµÄ$l",
                "dodge":                10,
		"parry":		-10,
                "damage":               35,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$n¿´×¼À´ÊÆ£¬ÒÔ$WÏò$NµÄ±øÈÐÃÍµã¡£Ö»Ìý¡¸µ±¡¹µÄÒ»Éù¾ÞÏì£¬¹ûÈ»½«$NµÄ±øÈÐµ´ÁË¿ªÈ¥¡£\n",
		"parry_power":		10,
        ]),
        ([      "name":                 "¡¸³öÃ»·ç²¨Àï¡¹",
                "action":
"$NÍ»È»Á³ÉÏÇàÆøÒ»ÏÔ£¬²æÉÏÎËÎËÖ®Éù´ó×ö£¬Õýµ±$n¾ª²ïÊ±£¬\n"
"$N¿ñ·çÖèÓê°ãÁ¬¹¥Îå²æ¡£ÕâÕÐ[1;32m¡¸³öÃ»·ç²¨Àï¡¹[2;37;0mÊÇÕûÌ×²æ·¨µÄ¾«Ëè£¬\n"
"Ê©½«³öÀ´£¬²»µ«±ä»ÃÄª²â£¬ÇÒÉùÊÆ¾ªÈË£¬$n¶ÙÊ±²»ÖªËù´ë",
                "dodge":                -5,
		"parry":		-5,
                "damage":               40,
                "damage_type":  	"´ÁÉË",
		"parry_msg":
"$n²»¹Ë×ÔÉí£¬ÊÖÖÐ$WÁ¬Á¬´ÌÏò$N¡£ÕâÎ§Îº¾ÈÕÔÖ®¼Ç¹ûÈ»×àÐ§£¬½«$N±ÆÁË»ØÈ¥¡£\n",
		"parry_power":		15,
        ]),
});


int valid_learn(object me)
{
        object ob;

	if (me->query("class") != "dragon")
		return notify_fail("Äã·ÇÁú×å£¬ÔõÄÜÏ°¹ßÕâË®ÖÐ³öÃ»µÄ²æ·¨£¿\n");
        if( (int)me->query("max_force") < 100 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬ÎÞ·¨Áì»á·ç²¨Ê®¶þ²æµÄ¾«ÃîÖ®´¦¡£\n");

	if (me->query_skill("dragonforce", 1) < me->query_skill("fengbo-cha", 1)/2)
		return notify_fail("ÄãµÄÁúÉñÐÄ·¨ÐÞÎªÌ«µÍ¡£\n");

        if (!(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "fork" )
                return notify_fail("Äã±ØÐëÏÈÕÒÒ»±ú²æÀ´²ÅÄÜÑ§²æ·¨¡£\n");
        return 1;
}

int practice_skill(object me)
{
//    int knowledge=me->query("longgong/·ç²¨Ê®¶þ²æ");
//   int mylev=me->query("fengbo-cha", 1);
//  string msg;

    if (me->query("class") != "dragon")
	return notify_fail("Äã·ÇÁú×å£¬ÔõÄÜÏ°¹ßÕâË®ÖÐ³öÃ»µÄ²æ·¨£¿\n");
    if(me->query_skill_mapped("force") !="dragonforce")
	return notify_fail("·ç²¨Ê®¶þ²æ±ØÐëÅäºÏÁúÉñÐÄ·¨²ÅÄÜ·¢»ÓÍþÁ¦¡£\n");
    if(me->query("kee") < 50) return notify_fail("ÄãµÄÌåÁ¦Ì«Èõ£¬ÏÈÐÝÏ¢Ò»»á¶ù°É¡£\n");
    if(me->query("sen") < 50) return notify_fail("ÄãµÄÉñÖÇ²»Çå£¬¾ÍËãÁ·ÁËÒ²Ê²Ã´¶¼Ñ§²»µ½µÄ¡£\n");
    if(me->query("force") < 20) return notify_fail("ÄãµÄÄÚÁ¦²»×ã£¬ÎÞ·¨ÕÕÂ·ÊýÎè²æ¡£\n");

    me->add("kee", -30);
    me->add("force", -3);
//    msg="$NÀ´À´»Ø»ØÁ·Ï°×Å·ç²¨Ê®¶þ²æ£¬ËÆºõÓÐÐ©³¤½ø¡£\n";
/*    if (knowledge != 1 && knowledge !=2) knowledge = 0;
    if (knowledge==1 || !knowledge)
        msg+=action[mylev/20]["name"];
    if (knowledge==2)
	msg+=action[mylev/15]["name"];
    msg+="ÕâÒ»ÕÐ¡£\n";
    msg+="mylev is "+mylev;
*/
//    message_vision(msg, me);
    return 1;
}

int valid_enable(string usage)
{
        return usage=="fork"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}
string query_parry_msg(object weapon)
{
    return action[random(sizeof(action))]["parry_msg"];
}
string perform_action_file(string func)
{
return CLASS_D("dragon") + "/fengbo-cha/" + func;
}
