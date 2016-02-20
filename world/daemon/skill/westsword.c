// 神话世界·西游记·版本４．５０
// By tianlin 2001.5.1
/* <SecCrypt CPL V3R05> */

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
   ([   "action":
"$N手中$w向$n的$l直劈过来。",
     "dodge":     -5,
                "parry":                -10,
     "damage":     50,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中$w向$n的$l斜劈过来。",
     "dodge":     -35,
                "parry":                -5,
     "damage":     50,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N手中的$w划了一个三角，向$n的$l刺了过去。",
     "dodge":     -10,
                "parry":                -15,
     "damage":     65,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w划了个大圆，向$n的$l刺了过去。",
     "dodge":     -30,
                "parry":                -5,
     "damage":     70,
     "damage_type":   "刺伤"
   ]),
   ([   "action":
"$N手中的$w对着$n的$l旋了过去。",
     "dodge":     -20,
                "parry":                -20,
     "damage":     120,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{

   object ob;

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "sword" )
     return notify_fail("你必须先找一把剑才能练剑法。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_westsword");
     if(me->query("skill_westsword")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
        {
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 3 )
     return notify_fail("你的内力或气不够，没有办法练习西洋剑法。\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
   write("你按著所学练了一遍西洋剑法。\n");
   return 1;
}


string perform_action_file(string func)
{
return CLASS_D("moon") + "/snowsword/" + func;
}

