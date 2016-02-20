// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
//by tianlin 2001/5/1
 
//bingpo-blade.c ¡¾±ùÆÇº®µ¶¡¿weikee...97.09.13.
//need ice blade to learn or practice this skill, want check out how 
//to force the use of a ice blade even when use this skill.

/*
±ùÆÇº®µ¶    dodge  -15   parry  5    damage  20
±ùÆÇº®µ¶µÄÌØµãÊÇ¿ì£¬ÍùÍùÊÇµ¶¹âÒ»ÉÁ£¬ÈËÍ·ÂäµØ¡£
µ«Ö»Òª²»¾ª²»»Å£¬ÑÏÃÜ·ÀÊØ£¬ËäÎªµ¶ÊÆ²øÈÆÒàÎÞ´ó°­£¬
±ùÆÇº®µ¶²»ÒÔÁ¦È¡Ê¤£¬¹ÊÉËº¦Á¦²»Ç¿¡£
*/

inherit SKILL;

mapping *action = ({
        ([      "name":                 "ÎÞ",
                "action":
"$NÇá¸§ÊÖÖÐµÄ$w£¬Í»È»¼äÖ»¼ûµ¶¹âÒ»ÉÁ£¬ÔÙÉÁ£¬ÓÖÒ»ÉÁ£¡
ÈýµÀ´Ì¹ÇµÄº®ÆøÒÑÈ»Ï®ÉÏÁË$nµÄ$l",
     "dodge":     -15,
     "parry":     5,
     "damage":     25,
     "damage_type":     "¸îÉË"
        ]),
        ([      "name":                 "ÎÞ",
                "action":
"Ö»¼û$Nµ¹Ìá$w£¬ÉíÐÎ¼±³å£¬¾ÍÔÚÓë$n´íÉíÖ®¼Ê£¬
Í»È»·´ÊÖÒ»µ¶´Ó$nºóÄÔÐ±Åü¶øÏÂ",
     "dodge":     -15,
     "parry":     5,
                   "damage":                  30,
                  "damage_type":     "ÅüÉË"
        ]),
        ([      "name":                 "ÎÞ",
                "action":
"$NÐ±Éí·ÉÆð£¬´ø³öÒ»Æ¬Æ¥Á·Ò²ËÆµÄµ¶¹â¾íÏò$nµÄ$l",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  35,
                   "damage_type":     "ÅüÉË"
        ]),
        ([      "name":                 "ÎÞ",
                "action":
"$NÍ»È»Ò»½ÅÌß³ö£¬ÊÖÖÐµÄ$w»®³öÒ»µÀÇáÃîµÄÔ²»¡£¬
µ­µ­µÄµ¶¹â·â×¡ÁË$nµÄÍ·Á³£¬ÇÐ¶ÏÁË$nµÄºôÎü",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  30,
                   "damage_type":     "¸îÉË"
        ]),
        ([      "name":                 "ÎÞ",
                "action":
"Ö»¼û$NÁ³É«Ò»º®£¬Ò»ÕÐ[1;37m¡¸Ç§Àï±ù·â¡¹[2;37;0mÊ¹³ö£¬´ÓÃ¼½Ýµ½½Å¸ú£¬
$nÖÜÉíµÄÑªÒº¶¼ËÆ±»ÕâÎÞ¾¡µÄµ¶ÊÆ¶³×¡£¬¶øÉúÃüÒ²·Â·ðÒªÀëÌå¶øÈ¥",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  40,
                   "damage_type":     "ÅüÉË"
        ]),   
        ([      "name":                 "ÎÞ",
                "action":
"$Nµ¶ÊÆ½¥Âý£¬¶ø$wÉÏ´ø³öµÄº®ÆøÈ´Ô½À´Ô½Å¨¡£
¾ÍÔÚÕâÊ±£¬$nµÄÐÄÍ·Ò»½ô£¬Ò»µÀ±ÈÕë¼â»¹ÒªÈñÀûµÄº®ÆøÒÑ´ÌÉÏÁË$n$l",
                  "dodge":                   -15,
     "parry":     5,
                   "damage":                  30,
                   "damage_type":     "´ÌÉË"
        ]),   
        ([      "name":                 "ÎÞ",
                "action":
"$NÒ²²»¹ÜÈýÆß¶þÊ®Ò»£¬¸ß¾Ù$wºô£¡µØ¾ÍÊÇÒ»µ¶Ïò$nÓ­ÃæÕ¶ÏÂ£¡
ËäÈ»Ö»ÓÐÒ»µ¶£¬¿ÉÅÂµÄµ¶ÊÆÈ´ËÆÍò¹Å²»»¯µÄº®±ù·âËÀÁË$nµÄÒ»ÇÐÍËÂ·",
                   "dodge":                   -15,
     "parry":     5,
                   "damage":                  30,
                   "damage_type":     "ÅüÉË"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("ÄãµÄÄÚÁ¦²»¹»£¬Ã»ÓÐ°ì·¨Á·±ùÆÇº®µ¶£¬
¶àÁ·Ð©ÄÚÁ¦ÔÙÀ´°É¡£\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "blade"
        ||      (string)ob->query("material") != "ice" )
                return notify_fail("Äã±ØÐëÏÈÕÒÒ»°Ñ±ù×öµÄµ¶²ÅÄÜÁ·±ùÆÇº®µ¶¡£\n");

        return 1;
}

int valid_enable(string usage)
{
  return usage =="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("ÄãµÄÄÚÁ¦»òÆø²»¹»£¬Ã»ÓÐ°ì·¨Á·Ï°±ùÆÇº®µ¶¡£\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("Äã°´×ÅËùÑ§Á·ÁËÒ»±é±ùÆÇº®µ¶¡£\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
 return CLASS_D("yaomo")+"/xueshan/bingpo-blade/"+action;
}
//by tianlin 2001.8.5.ÐÞ¸ÄÈ¥µô±ù¶¾º¯Êý
/*
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
        if( random(me->query_skill("ningxie-force")) > 5) {
                victim->apply_condition("bp_poison", random(2) + 1 +
                        victim->query_condition("bp_poison"));
        }
}
*/