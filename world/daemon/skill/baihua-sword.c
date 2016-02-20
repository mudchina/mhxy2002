// baihua-sword

inherit SKILL;

mapping *action = ({
([      "action" : "$N一招「柳絮风飘」，$w轻灵地划出几个圆弧，\n幻出漫天花絮般的剑芒，向$n的$l刺去",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一个纵身，随手一式「小园艺菊」，\n手中$w迅疾向$n的下盘连刺三剑",
        "dodge" : -15,
        "parry" : -20,
        "damage" : 50,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左手剑诀一领，右手$w一颤，\n分两路刺向$n的$l，正是一招「双蝶迷回」",
        "dodge" : -40,
        "parry" : -20,
        "damage" : 45,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「幽兰空谷」，$w看似随意地一挥，\n剑尖却从$n不可思议的角度攻入",
        "dodge" : -20,
        "parry" : -15,
        "damage" : 35,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「茶花满路」，身形急晃。\n一时间空中尽是$w的影子，令$n不知如何抵挡",
        "dodge" : -15,
        "parry" : -15,
        "damage" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「牡丹含泪」，$w绕出数个银圈，平平地向$n的$l卷去",
        "dodge" : -15,
        "parry" : -25,
        "damage" : 30,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招「芍药蕴珠」，$w向$n的$l刺去",
       "dodge" : -15,
        "parry" : -10,
        "damage" : 35,
        "damage_type" : "刺伤"
]),
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 200 )
                return
               notify_fail("你的内力不够，没有办法学百花素芯剑法。\n");

        if( me->query("family/family_name") != "轩辕界" )
        return notify_fail("只有本门中人才能学此剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return
notify_fail("你必须先找一把剑才能学百花素芯剑剑法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return (usage=="sword") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        object weapon;

        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑，才能练剑法。\n");

        if( (int)me->query("kee") < 40 )
                return
notify_fail("你的体力不够练这套剑法，还是先休息休息吧。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string func)
{
return CLASS_D("xuanyuan") + "/baihua-sword/" + func;
}
