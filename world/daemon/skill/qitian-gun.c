// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */

inherit SKILL;
#include <ansi.h>;

string* skill_head =({
        "[31mÖ»¼û$NÉíÌåÒ»Íá£¬Ò»ÕÐ[m",
        "[32m$NÒ»Éù³¤Ïø£¬Ò»ÕÐ[m",
        "[33m$NÒ»ÌáÆø£¬Ê¹³öÒ»ÕÐ[m",
        "[34m$NÒ»Éù¶ÏºÈ£¬Ò»Ê½[m",
        "[35m$NÊ¹³ö[m",
        "[36m$NÌáÆø·¢Á¦£¬´óºðÒ»Éù£¬Ê¹³ö[m",
});

string* skill_tail =({
        "[31m£¬ÊÖÖÐ$wÏò$nµÄ$l¹¥À´£¡[m",
        "[32m£¬ËæÊÖÒ»°ôÏò$nµ±Í·ÔÒÏÂ[m",
        "[33m£¬Ö»¼û$w³¯$n¼±ËÙ·ÉÈ¥¡£[m",
        "[34m£¬ÊÖÖÐ$w»º»ºµÄÂäÏò$n£¬µ«ÕâÆäÖÐÔÌ²ØÎÞÏÞÉ±»ú¡£[m",
        "[35m£¬ÊÖÖÐ$wËÆÇáÊµÖØ£¬Õæ±¼$w¡£[m",
        "[36m£¬ÊÖÖÐ$w¹âÃ¢±©ÕÇ£¬Ö±ÕÖ$n¡£[m",
});

mapping *action = ({
        ([      "name":                 "Ò»¹÷¶¨Ç¬À¤",
                "action":
"Ö»¼û$NÉíÌåÒ»Íá£¬ÊÖÖÐµÄ$wÖ±±¼$nµÄÄÔÃÅ£¬$n´ó³ÔÒ»¾ª.",
                "dodge":                5,
               "parry":   -10,
                "damage":               60,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "name":                 "°ô´òÓñµÛ",
                "action":
"$NÒ»Éù³¤Ïø£¬Ò»ÕÐ[1;32m¡¸°ô´òÓñµÛ¡¹[m£¬$wÏò$nÈ«ÉíÒªº¦¹¥À´£¡",
                "dodge":                0,
     "parry":     0,
                "damage":               55,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "name":                 "ºáÉ¨Ìì¹¬",
                "action":
"$NÕ¾¶¨ÉíÐÍ£¬ÊÖÖÐ$wÏòÌìÒ»Ö¸£¬Ò»¸ö´óÔ²Ö±¶Ô$nÂäÏÂ",
                "dodge":                10,
     "parry":   -20,
                "damage":               45,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "name":                 "ÆëÌìÓÖÒ»¹÷",
                "action":
"$NÒ»Éù¾ÞºÈ£¬ºÃÒ»¸ö"+HIW"¡¸ÆëÌìÓÖÒ»¹÷¡¹"NOR+"£¡\n¾ÍÔÚ$nÒ»ã¶Ö®¼ä£¬$NÊÖÖÐ$wÒÑÊÇºôÐ¥¶øÖÁ£¬É¨Ïò$nµÄ$l",
                "dodge":               10,
     "parry":   -15,
                "damage":               55,
                "damage_type":  "ÔÒÉË"
        ]),
        ([      "name":                 "ÎÞÉùÊ¤ÓÐÉù",
                "action":
"$NÒ»ÕÐ[1;33m¡¸ÎÞÉùÊ¤ÓÐÉù¡¹[m»º»ºµÄÂäÏò$n£¬µ«ÕâÆäÖÐÔÌ²ØÎÞÏÞÉ±»ú¡£",
                "dodge":                -5,
     "parry":     -5,
                "damage":               40,
                "damage_type":  "ÔÒÉË"
        ]),   
        ([      "name":                 "Á÷ÐÇ¸ÏÔÂ",
                "action":
     "$NÒ»ÌáÆø£¬Ê¹³öÒ»ÕÐ[1;37m¡¸Á÷ÐÇ¸ÏÔÂ¡¹[mÖ»¼û$w³¯$n¼±ËÙ·ÉÈ¥¡£",
                "dodge":                5,
     "parry":   -10,
                "damage":               35,
                "damage_type":  "ÔÒÉË"
        ]),   
   ([   "name":        "Ê¥¹÷Ò»»÷",
     "action": 
    "$NÊ¹³öÁË×îºóµÄ¾øÕÐ[1;35m¡¸Ê¥¹÷Ò»»÷¡¹[m£¬$n»¹Ã»ÅªÇåÔõÃ´»ØÊÂ£¬$NÊÖÖÐµÄ$wÒÑ¾­ÂäÔÚ×Ô¼ºµÄÍ·ÉÏ£¡",
     "parry":   -40,
     "dodge":   -100,
     "damage":   250,
     "damage_type":  "ÔÒÉË"
   ]),
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓÐ°ì·¨Á·ÆëÌì¹÷·¨£¬¶àÁ·Ð©ÄÚÁ¦ÔÙÀ´°É¡£\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("Äã±ØÐëÏÈÕÒÒ»¸ù°ô×Ó²ÅÄÜÁ·°ô·¨¡£\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_qitian-gun");
     if(me->query("skill_qitian-gun")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 50
        ||      (int)me->query("force") < 5 )
                return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓÐ°ì·¨Á·Ï°ÆëÌì¹÷·¨¡£\n");
        me->receive_damage("kee", 30);
        me->add("force", -10);
        write("Äã°´×ÅËùÑ§Á·ÁËÒ»±éÆëÌì¹÷·¨¡£\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
return CLASS_D("houyao") + "/qitian-gun/" + action;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("qitian-gun",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"Äã¶ÔÆëÌì¹÷µÄÁìÎò¼ÓÉîÁË£¬ÄãµÄÆëÌì¹÷½øÈëÁËÒ»¸öÐÂµÄ¾³½ç£¡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"È»¶øÄãµÄÐÄÖÐ¾ÓÈ»²úÉúÁËÒ»ÖÖÊ§Âä¸Ð£¡\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"È»¶øÄãµÄÐÄÖÐÉýÆðÒ»ÖÖã°âêµÄ¸Ð¾õ£¬·Â·ðÓÐÒ»Ë¿ÖØÒªµÄ¶«Î÷Ã»ÓÐ×¥×¡¡£\n"NOR);
       return;
     }
     tell_object(me,HIW"ÄãÍ»È»¸£ÖÁÐÄÁé£¬¶ÔÆëÌì¹÷ÁìÎò³öÁËÒ»ÕÐÐÂµÄÓÃ·¨£¡\n"NOR);
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

   m_actions=me->query("skill_qitian-gun");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"ÔÒÉË"]);

   if(!arg||arg==" ")arg="ÆëÌì¹÷¾ø¼¼"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"¡¸"+arg+"¡¹"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_qitian-gun",m_actions);
}
