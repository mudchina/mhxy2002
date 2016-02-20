//离别羽
//creat by focus
inherit SKILL;
#include <ansi.h>


mapping *action = ({
   ([  "action": HIW"$N手上的翎羽经由中指，拇指夹住，食指一点，径往$n的$l刺去"NOR,
     "dodge":     5,
     "damage":     35,
     "damage_type":   "刺伤"
   ]),
([ "action":HIM"只见$N手腕一振，翎羽上的羽丝全部散开如蒙，一片羽丝中，羽茎已经刺入$n的$l"NOR,
     "dodge":     -5,
     "damage":     40,
     "damage_type":   "刺伤"
   ]),
   (["action":HIW"白毫已散如雾；雾，笼月于无涯中，茎，深深的刺入$n的$l"NOR,
     "dodge":     -5,
     "damage": 60,
     "damage_type":   "刺伤"
   ]),
   ([ "action":HIM"白毫如纱、如诗、如梦、如....情人的轻吻, 羽茎如闪电，划向$n的$l"NOR,
     "dodge":     10,
     "damage": 45,
     "damage_type":   "割伤"
   ]),
  ([  "action": HIW"$N抬手，翎羽自随扬起之势奔出，羽毫散，散如浓雾，羽茎已扎入$n的$l"NOR,
     "dodge":     0,
     "damage": 60,
     "damage_type":   "刺伤"
   ]),
  ([ "action": HIM"$N手中白毫连续的颤动，如同泛江逐月的舟舫，那么不畏、痴情，孤独，$n醉了，醉在那不可思仪的韵律...羽毫已划到$n的$l"NOR,
     "dodge":     -5,
     "damage":     60,
     "damage_type":   "割伤"
   ]),
});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 50 )
    return notify_fail("你的内力不够,没有办法练离别羽.\n");

   if( !(ob = me->query_temp("weapon"))
   ||   (string)ob->query("skill_type") != "yumao" )
     return notify_fail("你必须一根才白毫翎羽能练习离别羽。\n");

   return 1;
}

int valid_enable(string usage)
{
   return usage=="yumao" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     mapping* m_actions;
     m_actions=me->query("skill_libieyu");
     if(me->query("skill_libieyu")==0 )
     return action[random(sizeof(action))];
     if( random(4) == 1 )
     return m_actions[random(sizeof(m_actions))];
     else
     return action[random(sizeof(action))];
}

int practice_skill(object me)
{
   if( (int)me->query("kee") < 30
   ||   (int)me->query("force") < 10 )
    return notify_fail("你的内力或气不够,没有办法练习离别羽.\n");
   me->receive_damage("kee", 30);
   me->add("force", -3);
  write(HIB"酒醒寂寞饮小雨，又醉离别落大梦\n"NOR, me);
   return 1;
}

string perform_action_file(string func)
{
  return CLASS_D("lingjie") + "/libieyu/" + func;
}
