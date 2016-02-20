//[4;53m[1;31mBy tianlin@mhxy for 2002.1.25[2;37;0m
//´ÓÐÂ±àÐ´
#include <ansi.h>
inherit SKILL;
string* skill_head =({
        "$NÉíÐÎÉÔÍË£¬Ê¹³öÒ»ÕÐ",
        "$NÓÚëüëüëÊëÊÖÐ£¬Ê¹³öÒ»ÕÐ",
        "$NËÄ´¦ÓÎ×ß£¬Ò»ÕÐ",
        "$NÉñÌ¬ÓÆÏÐ£¬Ò»ÕÐ",
        "$NÖÐ¹¬Ö±½ø£¬Í»È»Ò»ÕÐ",
        "$NË«½ÅÒ»¶Ù£¬±ÊÖ±Ô¾Æð£¬Ò»ÕÐ",
});

string* skill_tail =({
        "£¬ÊÖÖÐ$w²»Í£µØ²ü¶¶×Å",
        "£¬ÊÖÖÐ$w¶Ô×¼$nµÄ$lÁè¿ÕÒ»Õ¶",
        "£¬·´ÊÖ½«$w¶Ô×¼$n$lÒ»½£´ÌÈ¥",
        "£¬ÊÖÖÐ$wÇáÃîµØ»®Ïò$nµÄ$l",
        "£¬ÊÖÖÐ$wÈ¥ÊÆÆ®ºö²»¶¨£¬Ö»¿´µÃ$nÑÛ»¨çÔÂÒ",
        "£¬ÊÖÖÐ$w´øÆðµãµãº®¹â£¬Ö¸Ïò$nÇ°ÐØÑ¨µÀ",
});

mapping *action = ({
        ([    "action":           "$NÊÖÖÐ$wµÄËæ·ç¶ø³ö£¬Ò»ÕÐ"HIR"¡¸¾øÃü¡¹"NOR"£¬$n±»ÁýÕÖÔÚÒ»Æ¬½£¹âÖ®ÖÐ",
	       "dodge":		0,
	       "damage":		30,
              "damage_type":      "´ÌÉË"
        ]),
        ([    "action":           "$NÊ¹³ö¶áÃüÊ®Èý½£ÖÐµÄ"HIB"¡¸¶áÃü¡¹"NOR"£¬ÊÖÖÐ$wÓÐÈçÇàºç£¬Ö±»®$nµÄ$l",
	       "dodge":		0,
	       "damage":		30,
              "damage_type":      "¸îÉË"
        ]),
        ([    "action":           "$NÒ»ÕÐ"HIY"¡¸É¥Ãü¡¹"NOR"£¬$w»¯×÷ÆæÒìµÄ»¡ÏßÖ±È¡$nµÄ$l",
	       "dodge":		0,
	       "damage":		30,
              "damage_type":      "¸îÉË"
        ]),
        ([    "action":           "$NÊÖÖÐ$wÐéÊµÏà¼ä£¬Ò»Ê½"CYN"¡¸ÍöÃü¡¹"NOR"£¬Ïò$nµÄ$lÅü³ö",
	       "dodge":		0,
	       "damage":		30,
              "damage_type":      "¸îÉË"
        ]),
        ([    "action":           "$NÊÖÖÐ$wÎÞÓ°ÎÞ×Ù£¬Í»µÄÒ»ÕÐ"HIR"¡¸ÎÞÃü¡¹"NOR"¶Ô×¼$n$lÒ»ÏÂ´ÌÈ¥",
	       "dodge":		0,
	       "damage":		30,
              "damage_type":      "´ÌÉË"
        ]),
});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("ÄãµÄÄÚÁ¦ÐÞÎª²»¹»Éî£¬¶áÃü½£·¨Ñ§ÁËÒ²Ã»ÓÃ¡£\n");

	if( (string)me->query_skill_mapped("force")!= "cloudforce")
		return notify_fail("¶áÃü½£·¨±ØÐëÅäºÏÉñ½£É½×¯µÄÄÚ¹¦²ÅÄÜÁ·¡£\n");

	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "sword" )
		return notify_fail("Äã±ØÐëÏÈÕÒÒ»±ú½£²ÅÄÜÁ·Ï°½£·¨¡£\n");
	return 1;
}

int practice_skill(object me)
{
	int dod=(int)me->query_skill("dodge");
	int swo=(int)me->query_skill("duo-sword");

	if (dod<swo/2)
		return notify_fail("ÄãµÄÉí·¨¸ú²»ÉÏ½£·¨£¬Á·ÏÂÈ¥ºÜ¿ÉÄÜ»áÉËµ½×Ô¼º¡£\n");
	if ((int)me->query("kee") < 30)
		return notify_fail("ÄãÌåÖÊÇ·¼Ñ£¬Ç¿Á·¶áÃü½£·¨ÓÐº¦ÎÞÒæ¡£\n");
	if ((int)me->query("force") < 5)
		return notify_fail("ÄãÄÚÁ¦²»×ã£¬Ç¿Á·¶áÃü½£·¨ÓÐ×ß»ðÈëÄ§µÄÎ£ÏÕ¡£\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("$NÄ¬Ä¬»ØÒäÁËÒ»»á¶ù£¬È»ºóÁ·ÁËÒ»±é¶áÃü½£·¨¡£\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword"||usage=="parry";
}
mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_duo-sword");
     if(me->query("skill_duo-sword")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else 
    return action[random(sizeof(action))];

}
string perform_action_file(string func)
{
        return CLASS_D("shenjian") + "/duo-sword/" + func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("duo-sword",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"Äã¶Ô¶áÃü½£·¨µÄÁìÎò¼ÓÉîÁË£¬ÄãµÄ¶áÃü½£·¨½øÈëÁËÒ»¸öÐÂµÄ¾³½ç£¡\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"È»¶øÄãµÄÐÄÖÐ¾ÓÈ»²úÉúÁËÒ»ÖÖÊ§Âä¸Ð£¡\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"È»¶øÄãµÄÐÄÖÐÉýÆðÒ»ÖÖã°âêµÄ¸Ð¾õ£¬·Â·ðÓÐÒ»Ë¿ÖØÒªµÄ¶«Î÷Ã»ÓÐ×¥×¡¡£\n"NOR);
       return;
     }
     tell_object(me,HIW"ÄãÍ»È»¸£ÖÁÐÄÁé£¬¶Ô¶áÃü½£·¨ÁìÎò³öÁËÒ»ÕÐÐÂµÄÓÃ·¨£¡\n"NOR);
     tell_object(me,"ÇëÎªÕâÕÐÈ¡Ò»¸öÃû×Ö£º");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_duo-sword");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"´ÌÉË"]);

   if(!arg||arg==" ")arg="¶áÃü½£·¨¾ø¼¼"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HBRED+HIW"¡¸"+arg+"¡¹"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_duo-sword",m_actions);
}
