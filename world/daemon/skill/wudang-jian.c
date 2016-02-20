//wudang-jian.c 武当剑法
// modified by Venus Oct.1997
inherit SKILL;

mapping *action = ({
([      "name":   "飞燕入林",
    "action" : "$N身体左转，左手剑指，两腿屈膝，右前臂内旋，剑尖前端一寸处短促抖腕发
力，一招「飞燕入林」，手中$w轻轻颤动，一剑自上而下扎向$n的$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "青龙吐水",
    "action" : "$N身形不动，右前臂外旋，剑刃上崩，立马左腿左弓步，一招「青龙吐水」，手
中$w向前下反刺，一剑指向$n的$l",
    "force" : 120,
    "dodge" : 20,
    "damage" : 20,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "凤凰挚窝",
    "action" : "$N左脚向前一步，蹬地跳起，身体腾空疾速左转，右手$w先向前刺，随转体变
向，使出一式「凤凰挚窝」，剑光如匹练般泄向$n的$l",
    "force" : 140,
    "dodge" : 15,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "白蛇吐信",
    "action" : "$N碎步急进，提剑沿剑身方向疾速上崩，一招「白蛇吐信」直取$n的$l",
    "force" : 150,
    "dodge" : 15,
    "damage" : 35,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "玉女穿梭",
    "action" : "$N平剑斜洗，臂圆剑直，双脚交替弧形迈进，右手$w使出一式「玉女穿梭」，
剑锋往来运转如梭，连绵不绝刺向$n的$l",
    "force" : 130,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "仙人指路",
    "action" : "$N屈腕抬臂，剑由前向后上方抽带，挺起中平剑奋勇向前，右手$w使出一式
「仙人指路」刺向$n的$l",
    "force" : 120,
    "dodge" : 25,
    "damage" : 25,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "怀中抱月",
    "action" : "$N左撤步，抱剑当胸，挥剑做圆环形，正反搅动，右手$w一式「怀中抱月」，
剑意圆润，刺向$n的$l",
    "force" : 110,
    "dodge" : 15,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),
([      "name":   "反身朝阳",
    "action" : "$N侧身退步，左手剑指划转，腰部一扭，上体后仰，右手$w一记「反身朝阳」
自下上撩指向$n的$l",
    "force" : 150,
    "dodge" : 35,
    "damage" : 40,
    "lvl" : 0,
    "damage_type" : "刺伤"
]),

});


int valid_enable(string usage) { return (usage == "sword") || (usage == "parry")
; }

int valid_learn(object me)
{
    if ((int)me->query("max_force") < 10)
   return notify_fail("你的内力不够。\n");
    if ((int)me->query_skill("force", 1) < 20)
   return notify_fail("你的内功火候太浅。\n");
    if ((int)me->query_skill("unarmed", 1) < 20)
   return notify_fail("你的基本拳脚火候太浅。\n");
    return 1;
}

mapping query_action(object me, object weapon)
{
    int i, level;
    level   = (int) me->query_skill("wudang-jian",1);
    for(i = sizeof(action); i > 0; i--)
   if(level > action[i-1]["lvl"])
     return action[NewRandom(i, 20, level/5)];

}

int practice_skill(object me)
{
    object weapon;

    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
   return notify_fail("你使用的武器不对。\n");
    if ((int)me->query("kee") < 20)
   return notify_fail("你的体力不够练武当剑法。\n");
    me->receive_damage("kee", 10);
    return 1;
}

