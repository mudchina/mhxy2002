// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */


inherit SKILL;

#include <ansi.h>;

string* skill_head =({
        "[31m$NÄó×ÅÊÖÖÐµÄ$w£¬Ò»ÕÐ[m",
        "[32m$NÊÖÖÐµÄ$wÒ»¶¶£¬Ò»Ê½[m",
        "[33m$NÒ»ÍÆÊÖÖÐµÄ$w£¬Ê¹³ö[m",
        "[34m$NÊÖÖÐµÄ$wÈôÒþÈôÏÖ£¬Ê¹³öÒ»Ê½[m",
        "[35m$NÊÖÖÐ$wÈç·É£¬Ê¹³öÒ»ÕÐ[m",
        "[36m$NÊÖÖÐ$wÒ»³Á£¬Ò»Ê½[m",
     });

string* skill_tail =({
        "[31m£¬´ÌÏò$nµÄ$l¡£[m",
        "[32m£¬¶Ô$nµÄ$l¼²´Ì¹ýÈ¥¡£[m",
        "[33m£¬¾ÓÈ»ÂÕ³ÉÁËÒ»¸öÔ²£¬ÕÖÏò$nµÄÈ«Éí¡£[m",
        "[34m£¬´ÌÏò$nµÄÒªº¦²¿Î»¡£[m",
        "[35m£¬ÉîÉîµÄ´Ì½øÁË$nµÄ$l[m",
        "[36m£¬$wÏò$n¼±ËÙ·ÉÈ¥¡£[m",
});

mapping *action = ({
([      "action" : "$NÄó×ÅÊÖÖÐµÄ$w£¬Ò»ÕÐ¡¸ÉñÕë´ÌÂö¡¹£¬´ÌÏò$nµÄ$l¡£",
        //"force" : 120,
        "dodge" : -10,
        "parry" : 5,
        "damage" : 45,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊÖÖÐµÄ$wÒ»¶¶£¬$w·¢³öÒ»µÀÐüÄ¿µÄ¹âÃ¢£¬´ÌÏò$nµÄÒªº¦¡£",
        //"force" : 130,
        "dodge" : -10,
        "parry" : 10,
        "damage" : 50,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÇáÇáÒ»ÍÆÊÖÖÐ$w£¬¾Í¼û$wÏò$n¼²´Ì¹ýÈ¥¡£",
        //"force" : 140,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 55,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊÖÖÐµÄ$wÈôÒþÈôÏÖ£¬Í»È»¾Í¼û$wÏò$nµÄÒªº¦´ÌÈ¥¡£",
        //"force" : 160,
        "dodge" : -5,
        "parry" : 5,
        "damage" : 60,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊÖÖÐ$wÒ»³Á£¬$wËÆºõÓÐÇ§¾ûÖØ£¬Ö±Ïò$nÑ¹ÏÂ¡£",
        //"force" : 180,
        "dodge" : 10,
        "parry" : 5,
        "damage" : 65,
        "damage_type" : "¸îÉË"
]),
([      "action" : "$NÊÖÖÐÒ»¸öÐ¡Ð¡µÄ$w¾ÓÈ»ÂÕ³ÉÁËÒ»¸öÔ²£¬ÕÖÏò$nµÄÈ«Éí¡£",
        //"force" : 210,
        "dodge" : -15,
        "parry" : 15,
        "damage" : 75,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$NÊÖÖÐ$wÒ»ÉÁ£¬$n¶ÙÊ±¾õµÃÃÔ»ó²»½â£¬Í¬Ê±¾Í¼û$wÒÑ¾­Ìù½üÁË$nµÄ$l¡£",
        //"force" : 240,
        "dodge" : 5,
        "parry" : 15,
        "damage" : 70,
        "damage_type" : "´ÌÉË"
]),
([      "action" : "$N´óºðÒ»Éù£¬$wÈç·É£¬Ö»¼û$nµÄ$l¾ÍÒª±»$w´Ìµ½¡£",
        //"force" : 280,
        "dodge" : -20,
        "parry" : 10,
        "damage" : 60,
        "damage_type" : "¸îÉË"
]),
});


int valid_enable(string usage) { return (usage == "needle") || (usage == "parry"); }

int valid_learn(object me)
{
        if ((int)me->query("max_force") < 50)
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»¡£\n");
        if ((int)me->query_skill("xuanhu-xinfa", 1) < 20)
                return notify_fail("ÄãµÄÐþºüÐÄ·¨»ðºòÌ«Ç³¡£\n");
        if ((int)me->query_skill("fox-hand", 1) < 20)
                return notify_fail("ÄãµÄºüÊÖ»ðºòÌ«Ç³¡£\n");
        return 1;
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_tianyi-zhen");
     if(me->query("skill_tianyi-zhen")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    return action[random(sizeof(action))];

}

int practice_skill(object me)
{
            object ob;

    if(!objectp(ob=me->query_temp("weapon"))
|| (string)ob->query("skill_type") != "needle")
                return notify_fail("ÄãÊ¹ÓÃµÄÎäÆ÷²»¶Ô¡£\n");
        if ((int)me->query("kee") < 50)
                return notify_fail("ÄãµÄÌåÁ¦²»¹»Á·ÌìÒÂÕë·¨¡£\n");
        me->receive_damage("kee", 30);
        return 1;
}
          string perform_action_file(string action)
  { return CLASS_D("xuanyuan")+"/tianyi-zhen/"+action;}



void skill_improved(object me)
{
   int m_skill=me->query_skill("tianyi-zhen",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"Äã¶ÔÌìÒ»ÉñÕëµÄÁìÎò¼ÓÉîÁË£¬ÄãµÄÌìÒ»ÉñÕë½øÈëÁËÒ»¸öÐÂµÄ¾³½ç£¡\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"È»¶øÄãµÄÐÄÖÐ¾ÓÈ»²úÉúÁËÒ»ÖÖÊ§Âä¸Ð£¡\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"È»¶øÄãµÄÐÄÖÐÉýÆðÒ»ÖÖã°âêµÄ¸Ð¾õ£¬·Â·ðÓÐÒ»Ë¿ÖØÒªµÄ¶«Î÷Ã»ÓÐ×¥×¡¡£\n"NOR);
       return;
     }
     tell_object(me,HIW"ÄãÍ»È»¸£ÖÁÐÄÁé£¬¶ÔÌìÒ»ÉñÕëÁìÎò³öÁËÒ»ÕÐÐÂµÄÓÃ·¨£¡\n"NOR);
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

   m_actions=me->query("skill_tianyi-zhen");
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

   if(!arg||arg==" ")arg="ÌìÒ»ÉñÕë¾ø¼¼"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+"¡¸"+arg+"¡¹"
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_tianyi-zhen",m_actions);
}
