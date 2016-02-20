// by tianlin 2001.5.1
// 烈火剑法
// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 

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
        "，手中$w嗡嗡作响,幻成一道白光直刺$n的$l",
        "，$w发出一声清响,剑意若有若无,直取$n的$l",
        "，剑光如轮急转,晃得$n头晕目眩",
        "，手中$w虚幻不定地出现在$n周围.",
        "，剑光如水，洒向$n全身。",
});

mapping *action = ({
   ([  "action": "$N一招"HIY"「"NOR+HBBLU+HIR"烈火蔓延"NOR+HIY"」"NOR",手中$w嗡嗡作响,幻成一道白光直刺$n的$l",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "刺伤"
   ]),
([ "action":"只见$N纵身轻轻跃起,一招"HIR"「熊熊烈火」"NOR",剑光如水,一泄千里,洒向$n全身",
     "dodge":     0,
     "damage":     40,
     "damage_type":   "割伤"
   ]),
   ([   "action":
"$N飘然而进,手中$w微微震颤,刹那间连出九剑,分刺$w全身九个部位,正是一招"HIY"「"BLINK+HIW"究极"HIR"烈火"NOR+HIY"」"NOR".\n",
     "dodge":     0,
     "damage": 35,
     "damage_type":   "割伤"
   ]),
   ([ "action":
"$N中指轻弹剑锋,$w发出一声清响,剑意若有若无,直取$n的$l,却是一招"HIY"「"BLINK+WHT+HBRED"风光四发"NOR+HIY"」"NOR".\n",
     "dodge":     0,
     "damage": 45,
     "damage_type":   "刺伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("你的内力不够,没有办法练烈火剑法.\n");

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
     m_actions=me->query("skill_birds-sword");
     if(me->query("skill_birds-sword")==0 )
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
    return notify_fail("你的内力或气不够,没有办法练习烈火剑法.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
  write("你按着所学练了一遍烈火剑法.\n");
   return 1;
}

string perform_action_file(string action)
{
  return CLASS_D("yaomo/kusong") + "/liehuo-sword/" + action;
}

