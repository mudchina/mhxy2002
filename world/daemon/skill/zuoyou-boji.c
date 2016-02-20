// zuoyou-boji.c -左右搏击之术
// modified by Venus Oct.1997
#include <ansi.h>

inherit SKILL;

mapping *action = ({
([      "action" : "$N突然将右手握拳向天一举，仿佛被人捏住了一样，$n看得正纳闷，却突
然发现一个拳头夹着劲风击向自己的心窝",
    "force" : 300,
    "dodge" : 15,
    "damage_type" : "内伤",
    "lvl" : 0,
    "skill_name" : "握拳问天"
]),
([      "action" : "$N身形忽然一矮，左手已经变掌，斜向上方八步赶蝉般地疾拍$n的小
腹",
    "force" : 325,
    "dodge" : 55,
    "damage_type" : "内伤",
    "lvl" : 10,
    "skill_name" : "八步赶蝉"
]),
([      "action" : "$N伸出右拳往左掌心一拍，随即直捣黄龙般地攻向$n的头部",      
    "force" : 350,
    "dodge" : 10,
    "damage_type" : "内伤",
    "lvl" : 20,
    "skill_name" : "直捣黄龙"
]),
([      "action" : "$N突然伸出左掌猛拍自己的右肘，接着五指张开，反手迅速地挥向$n
的左脸，看来想在$n的脸上留下一座五指山",
    "force" : 375,
    "dodge" : 45,
    "damage_type" : "内伤",
    "lvl" : 30,
    "skill_name" : "五指成山"
]),
([      "action" : "$N双掌一拍，随即右掌攻向$n的左肩，$n急忙招架，$N的右掌却已变
拳猛地捣向$n的胸口",
    "force" : 400,
    "dodge" : 30,
    "damage_type" : "内伤",
    "lvl" : 40,
    "skill_name" : "声东击西"
]),
([      "action" : "$N左掌下，右掌上地前后一揉，随即一翻，左掌从右掌上滑出，推出
一股阳刚之劲袭向$n的胸口",
    "force" : 425,
    "dodge" : 15,
    "damage_type" : "内伤",
    "lvl" : 50,
    "skill_name" : "明日暗落"
]),
([      "action" : "$N双手在胸前一格，然后左手变拳击向$n的头部，$n勉力刚格开，却
发现$N的右掌已拍向自己的左肋下，不由大惊",
    "force" : 450,
    "parry" : 20,
    "dodge" : 50,
    "damage_type" : "内伤",
    "lvl" : 60,
    "skill_name" : "指南打北"
]),
([      "action" : "$N右手猛地抓住自己的左臂，但左手一转，便已变掌，并带着右手的
力量向前急冲而出劈向$n的$l",
    "force" : 500,
    "parry" : 30,
    "dodge" : 40,
    "damage_type" : "劈伤",
    "lvl" : 70,
    "skill_name" : "借力打力"
]),
([      "action" : "$N突然左臂前右臂后，呈十字形架在胸前，然后右臂骤然从左臂下滑
出，握拳向上斜勾而出，猛击$n的下颌骨！",
    "force" : 550,
    "parry" : 40,
    "dodge" : 5,
    "damage_type" : "内伤",
    "lvl" : 80,
    "skill_name" : "十字下勾"
]),
([      "action" : "$N忽然原地滴溜溜地一转，$n眼前就失去了$N的踪影。$n正左顾右盼
间，却见$N突然出现在眼前，笑嘻嘻地挥拳直打$n的小腹！！",
    "force" : 600,
    "parry" : 90,
    "dodge" : 80,
    "damage_type" : "内伤",
    "lvl" : 90,
    "skill_name" : "遁形出击"
])
});

int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry"; }  

int valid_learn(object me)
{
    if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
   return notify_fail("练左右搏击之术必须空手。\n");
    if ((int)me->query_skill("force", 1) < 30)
   return notify_fail("你的内功心法火候不够，无法练左右搏击之术。\n");
    if ((int)me->query("max_force") < 200)
   return notify_fail("你的内力太弱，无法练左右搏击之术。\n");
    if((int)me->query_skill("zuoyou-boji",1)<10)
   return notify_fail("左右搏击之术无法通过(learn)来获得进步。\n");
    return 1;
}

string query_skill_name(int level)
{
    int i;
    for(i = sizeof(action)-1; i >= 0; i--)
   if(level >= action[i]["lvl"])
      return action[i]["skill_name"];
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level = (int)me->query_skill("zuoyou-boji", 1);
    for(i = sizeof(action); i > 0; i--)
    if(level > action[i-1]["lvl"])
    return action[NewRandom(i, 20, level/5)];
}

int practice_skill(object me)
{
    if ((int)me->query("kee") < 40)
   return notify_fail("你的体力太低了。\n");
    if ((int)me->query("force") < 30)
   return notify_fail("你的内力不够练左右搏击之术。\n");
    if ((int)me->query_skill("zuoyou-boji",1) < 20)
   return notify_fail("以你目前的功力尚不够自己练习。\n");
    me->receive_damage("kee", 30);
    switch( random(3) ) {
    case 0:
    me->add("combat_exp", -5);
    write( HIR "你只觉得心绪一阵烦乱，头一阵发晕，你的经验降低了！\n" NOR);
    break;
    case 1:
    me->add("potential", random((int)me->query_con() + (int)me->query_skill("zuoyou-boji",1) )/20);
    me->add("combat_exp", random((int)me->query_con() + (int)me->query_skill("zuoyou-boji",1) )/10);
    write(HIG"你将左手和右手打来打去，练习左右搏击之术，增长不少实战经验，也
有所感悟，潜能获得了提高。\n");
    break;
    case 2:
    me->add("potential", -3);
    write( RED "你心有杂念，未能潜心练习，你潜能下降了！\n" NOR );
    break;
}
}
