//【应龙玄天棍】yinglong-stick
//update by swagger

inherit SKILL;
#include <ansi.h>
int ratio;
mapping *action = ({
([ 
      "action":"$N手中$w半提，半空中缓缓划向$n的$l",    
               "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               50,
                "damage_type":  "砸伤"
]),
([ 
     "action":"$N左掌护胸，右臂挟棍猛地扫向$n的腰间",

                "dodge":                0,
                        "parry":   -40,
                        "force":   40,
                "damage":               50,
                "damage_type":  "砸伤"
]),
([   
     "action":"$N倒竖$w，指天打地，向$n的$l劈去",
               "dodge":                -10,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
    "damage_type":"挫伤"
]),
([  
     "action":"$N横提$w，棍端划了个半圈，击向$n的$l",
                "dodge":                0,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
                "damage_type":  "砸伤"
]),
([  
     "action":"$N手中棍花团团，疾风般向卷向$n",  
                "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
                "damage_type":  "砸伤"
]),
([   
     "action":"$N单腿支地，一腿一棍齐齐击向$n的$l",
                "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
    "damage_type":"挫伤"
]),
([ 
     "action":"$N扭身反背，$w从胯底钻出，戳向$n的胸口",
                "dodge":                0,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
    "damage_type":"挫伤"
]),
([  
      "action":"$N腾空而起，如山棍影，疾疾压向$n",
                "dodge":                -5,
                        "parry":   -40,
                        "force":   40,
                "damage":               55,
                "damage_type":  "砸伤"
]),
        ([      "action":               
"$N使一招「苍龙出渊」，就在$n一愣之间，$N手中$w已自后向前呼啸而至，扫向$n的$l",
                "dodge":                -15,
                "parry":                -10,
                "damage" :              35,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N使出应龙中的「万龙群舞」，手中$w晃动，虚点一棍，突然自棍影中一棍扫向$n的$l",
                "dodge":                -10,
                "parry":                0,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N一招「天龙摆尾」，向前猛的一窜，手中$w反背一棍，直击$n的$l",
                "dodge":                10,
                "parry":                -5,
                "damage":               40,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N手中$w一式「天龙行空」，手中$w乱抖，铺天盖地杀来，招招不离$n的$l",
                "damage":                35,
                "dodge":                -10,
                "parry":                -10,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N的$w虚点，蓦地进步跟身，一招「龙腾四海」从$n意想不到的地方砸向$n的$l",
                "dodge":                -15,
                "parry":                -10,
                "damage":               30,
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N手中$w一递，竟如残月般弯转，一招「双龙戏珠」反手接连二棍对准$n$l砸去",
                "dodge":                0,
                "parry":                -10,
                "damage":               40,
                "damage_type":  "砸伤"
]),
});
string *liudao=({
                HIC"\n$N脚踏"HIY""BLINK"巽"NOR""HIC"位，一式"HIY"  蓝采和，提篮劝酒醉朦胧!"NOR,
                HIC"\n$N转踏"HIG""BLINK"坎"NOR""HIC"位，一式"HIG"  何仙姑，拦腰敬酒醉仙步!"NOR,
                HIC"\n$N再踏"HIM""BLINK"震"NOR""HIC"位，一式"HIM"  曹国舅，千杯不醉倒金盅!"NOR,
                HIC"\n$N又踏"HIR""BLINK"艮"NOR""HIC"位，一式"HIR"  韩湘子，铁棍提胸醉拔萧!"NOR,
                HIC"\n$N改踏"HIB""BLINK"离"NOR""HIC"位，一式"HIB"  汉钟离，跌步翻身醉盘龙!"NOR,
                HIC"\n$N换踏"YEL""BLINK"兑"NOR""HIC"位，一式"YEL"  铁拐李，踢倒金山醉玉池!"NOR,
                HIC"\n$N怪踏"HIC""BLINK"坤"NOR""HIC"位，一式"HIC"  张果老，醉酒抛杯倒骑驴!"NOR,
                HIC"\n$N奇踏"HIW""BLINK"乾"NOR""HIC"位，一式"HIW"  吕洞滨，酒醉提壶力千钧!"NOR,
                });
              
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，没有办法修行应龙玄天棍。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "stick" )
                return notify_fail("你必须先找一根棍子才能练棍法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="stick" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i,j;
	    mapping* m_actions;
		string strs;
		m_actions=me->query("skill_yinglong-stick");

        if( !me->query_temp("zuizj") ) {
           if(me->query("skill_yinglong-stick")==0) 
		    	return action[8+random(6)];
           if(random(0))
		    	return action[8+random(6)];
          return m_actions[random(sizeof(m_actions))];
		}
       else 
		   j=me->query_temp("zui")%8;
           message_vision(liudao[j],me);
           me->add_temp("zui",1);
        return action[j];
}
                

int practice_skill(object me)
{
        if( (int)me->query("kee") < 25
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习应龙棍法。\n");
        me->receive_damage("kee", 25);
        me->add("force", -5);
        write("你按着所学练了一遍应龙棍法。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}


string perform_action_file(string func)
{
return CLASS_D("wusheng") + "/yinglong-stick/" + func;
}

mixed fail_hit(object me, object victim)
{    if (me->query_temp("zuizj"))
      {
      switch (me->query_temp("zui")%8)
                    {
                        case 1: return HIC"$n远离"HIY"『巽位』"HIC"，弹指间便离位而去。\n"NOR;
                        case 2: return HIC"$n无视"HIG"『坎位』"HIC"，快步离开。\n"NOR;
                        case 3: return HIC"$n对"HIM"『震位』"HIC"不屑一顾，游弋之中。\n"NOR;
                        case 4: return HIC"$n对付"HIR"『艮位』"HIC"游刃有余，很快便杀出一条血路。\n"NOR;
                        case 5: return HIC"$n看到"HIB"『离位』"HIC"一现就远远的躲了开去。\n"NOR;
                        case 6: return HIC"$n反踏"YEL"『兑位』"HIC"，一个反身不见了。\n"NOR;
                        case 7: return HIC"$n一个小跃，已脱离了"HIC"『坤位』"HIC"。\n"NOR;
                        case 0: return HIC"$n轻松的一闪，避开了"HIW"『乾位』"HIC"。\n"NOR;
                        //default: return 1;
                    }
       }   
}      
mixed hit_ob_msg(object me,object victim)
{   string strs;
        if (me->query_temp("zuizj"))
      {//me->add_temp("zui",1);
      switch (me->query_temp("zui")%8)
              {
                        case 1: return HIY"$n陶醉于『巽位』中而不知返。\n"NOR;
                        case 2: return HIG"$n陷入『坎位』，不得其路。\n"NOR;
                        case 3: return HIM"$n被『震位』包围，吓得浑身直冒冷汗。\n"NOR;
                        case 4: return HIR"$n误入『艮位』，已经精疲力竭。\n"NOR;
                        case 5: return HIB"$n看到『离位』，不觉自己竟走了进去。\n"NOR;
                        case 6: return YEL"$n一闪，却正好闪入『兑位』。\n"NOR;
                        case 7: return HIC"$n自信的走入『坤位』，却怎么也走不出来。\n"NOR;
                        case 0: return HIW"$n眼看自己陷入『乾位』，却不知如何是好。\n"NOR;
               }
       }
}        
