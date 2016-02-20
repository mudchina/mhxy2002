//pangu-mace.c update by swagger

inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "action":               
"$N气运丹田，一声暴喝，好似焦雷一般，震得$n不知所措。\n"
"紧接一招「威镇四方」向$n的$l砸去", 
     "dodge":     10,
     "parry":     -10,
     "damage":     35,
     "damage_type":   "砸伤"
        ]),
        ([      "action":               
"$N一弹手中的$w，手中的$w向$n的$l雷霆般地砸下,\n"
"$n一愣之间，$w已到$n的$l。好一招「气壮山河」!",
     "dodge":     0,
     "parry":     -20,
     "damage":     50,
     "damage_type":   "砸伤"
        ]),
        ([      "action":               
"$N暴喝一声，腾空飞起，以泰山压顶之式向$n直扑而下，\n"
"手中的$w带着轰轰雷声，一招「千钧一发」砸向$n的$l", 
     "dodge":   10,
     "parry":   -20,
     "damage":   45,
     "damage_type":   "砸伤",
        ]),
        ([      "action":               
"$N手中的$w一转，一声大喝，一式「狂风暴雨」从四面八方盖向$n,\n"
"混乱中只见四面八方都是锏影，似乎已把$n逼入死路",
     "dodge":   0,
     "parry":   -25,
     "damage":   50,
     "damage_type":   "挫伤",
        ]),
        ([      "action":
"$N一抖手中的$w，划出一个圆圈，带出一片热浪，\n"
"一招「夏日狂阳」幻出一片锏影，虚虚实实的砸向$n的$l", 
     "dodge":   10,
     "parry":   -15,
     "damage":   30,
     "damage_type":   "挫伤",       
 ]),
        ([      "name":   "一",
    "action" : WHT"$N象疯了一般，双手持锏，呼的一声直直向$n头部砸下！"NOR,
    "dodge" : -15,
    "damage" : 65,
    "force"  : 65,
    "parry"  :-65,
    "damage_type" : "砸伤"
	]),
	([      "name":   "二",
    "action" : WHT"$N身形腾空而起，手中$w"WHT"幻出点点寒星，将$n全身都笼罩在内！"NOR,
    "dodge" : -15,
    "damage" : 70,
    "parry"  :-70,
    "force"  : 70,
    "damage_type" : "震伤"
	]),
	([      "name":   "三",
    "action" : WHT"$N身形刚一落地，就地一滚，连出数锏，招招不离$n的双脚！"NOR,
    "dodge" : -10,
    "damage" : 75,
    "parry"  :-75,
    "force"  : 75,
    "damage_type" : "戳伤"
]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return
notify_fail("你的内力不够，没有办法学习，等内力提高了再来吧。\n");

        if( (int)me->query("str") < 25 )
return notify_fail("你的体格太低，使不出盘古锏法。\n");
 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "mace" )
                return
notify_fail("你必须先找一根锏才能学盘古五式。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="mace")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
     int i;
	i=me->query("juesha");
	if( !me->query("juesha") ) {
     mapping* m_actions;
     m_actions=me->query("skill_pangu-mace");
     if(me->query("skill_pangu-mace")==0 )
     return action[random(5)];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
    	
        return action[random(6)];
	}else {
	return action[i];
	}
     
     
}


int practice_skill(object me)
{
        if( (int)me->query("kee") < 20
        ||      (int)me->query("force") < 5 )
                return
notify_fail("你的内力或气不够，没有办法练习。\n");
        me->receive_damage("kee", 25);
        me->add("force", -10);
        write("你按着所学练了一遍盘古五式。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string func)
{
return CLASS_D("xuanyuan") + "/pangu-mace/" + func;
}