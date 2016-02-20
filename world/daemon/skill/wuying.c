// wuying-sword 【无影剑】

/*
无影剑    dodge  -10    parry  -10    damage  65
此剑法为剑魔独孤求败中年时所创，剑魔中年时已经练得无剑胜有剑的境界，
出剑快如电闪、猛如雷鸣、狂如风卷、轻如云动，独此名为“无影剑”。间有
四招！分别为电、雷、风、云。
*/

inherit SKILL;
#include <ansi.h>

string* skill_head =({
        "$N一招",
        "只见$N纵身轻轻跃起,一招",
        "$N使出",
        "$N飘然而进，一式",
        "$N纵身轻轻跃起,剑光如轮急转，一招",
        "$N按剑而发，一招",
});


string* skill_tail =({
        "，手中$w不停地颤抖着",
        "，手中$w对准$n的$l凌空一斩",
        "，反手将$w对准$n$l一剑刺去",
        "，手中$w轻妙地划向$n的$l",
        "，手中$w去势飘忽不定，只看得$n眼花缭乱",
        "，手中$w带起点点寒光，指向$n前胸穴道",
});
mapping *action = ({
	([	"name":			"云",
		"action":
"$N一抖手中的$w，瞬间刺出三十六剑，这势"+BLINK""+HIW"「云」"NOR+"弄的$n顿时手忙脚乱，分不清虚实",
		"dodge":		-10,
                "parry":                -10,
		"damage":		35,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "风",
		"action":
"$N一剑刺向$n，$n急忙向旁边一闪，\n"
"不料$N一运劲儿，手中的$w突然弯了过来，这势"+BLINK""+HIC"「风」"NOR+"果然千变万化，转而刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		45,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "雷",
		"action":
"$N手中$w连续划出几个光环，这势"+BLINK""+MAG"「雷」"NOR+"犹如迅雷一阵吸力带得$n向前踏出一步，$N左手剑指已刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		55,
		"damage_type":		"刺伤"
	]),
	([	"name":                 "电",
		"action":
"$N一转身，背向$n，一式"+BLINK""+HIY"「电」"NOR+"手中$w从腋下反手刺向$n的$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		65,
		"damage_type":		"刺伤"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练无影剑。\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("你必须先找一把剑才能练剑法。\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        int i;
		mapping* m_actions;
		m_actions=me->query("skill_wuying");
        i=me->query_temp("WX_perform");
        if( !me->query_temp("WX_perform")) {
           if(me->query("skill_wuying")==0) return action[random(4)];
           if(random(2))return action[random(4)];
           m_actions=me->query("skill_wuying");
           return m_actions[random(sizeof(m_actions))];
        }
		else 
		{
         return action[i];
		}
		return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("你的内力或气不够，没有办法练习无影剑。\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("你按著所学练了一遍无影剑。\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string func)
{
	return CLASS_D("wusheng") + "/wuying/"+func;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("wuying",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"你对无影剑的领悟加深了，你的无影剑进入了一个新的境界！\n"NOR);
     if(random(me->query("kar"))<20){
        tell_object(me,HIW"然而你的心中居然产生了一种失落感！\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"然而你的心中升起一种惆怅的感觉，仿佛有一丝重要的东西没有抓住。\n"NOR);
       return;
     }
     tell_object(me,HIW"你突然福至心灵，对无影剑领悟出了一招新的用法！\n"NOR);
     tell_object(me,"请为这招取一个名字：");
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

   m_actions=me->query("skill_wuying");
   if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"刺伤"]);

   if(!arg||arg==" ")arg="无影剑必杀技"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIM"「"+arg+"」"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_wuying",m_actions);
}