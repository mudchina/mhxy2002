// 穿云腿法

inherit SKILL;

mapping *action = ({
([	"action" : "$N左腿虚晃踢出，不待落下，右脚紧跟着凌空踢出，一式「追风逐电」踢向$n的$l",
    "dodge" : 10,
	"parry" : -20,
    "damage_type" : "瘀伤",
	"skill_name" : "追风逐电"
]),
([	"action" : "$N突然一个铁板桥后翻，一式「倒踢北斗」，连向$n的$l踢出七腿",
        "dodge" : -5,
	   "parry" : -15,
        "damage_type" : "瘀伤",
	"skill_name" : "倒踢北斗"
]),
([	"action" : "$N使一式「登云步月」，拔地而起，左腿在空中一登，右腿趁式踢向$n的胸口",
        "dodge" : 15,
		"parry" : -10,
        "damage_type" : "内伤",
	"skill_name" : "登云步月"
]),
([	"action" : "$N呼的一声，身子盘旋飞起，一式「横扫九州」，右腿自后向前横扫$n的$l",
    "dodge" : -10,
    "parry" : -20,
    "damage_type" : "内伤",
	"skill_name" : "横扫九州"
]),
([	"action" : "$N身体凌空而起，双腿连环，使一式「雷霆天下」漫天腿影笼罩向$n",
     "dodge" : 0,
	"parry" : -20,
    "damage_type" : "震伤",
	"skill_name" : "雷霆天下"
]),
});
int valid_learn(object me)
{
	if( (int)me->query_skill("zhuanlong-force",1) < (int)me->query_skill("chuanyun-tui",1)/2)
		return notify_fail("你的心法还不够精湛，无法领会更深层的穿云腿！\n");


	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("练腿法必须空手。\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 50)
		return notify_fail("你的精神无法集中了，休息一下再练吧。\n");

	if( (int)me->query("kee") < 50 )
		return notify_fail("你现在手足酸软，休息一下再练吧。\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("你的内力不够了。\n");

	me->receive_damage("kee", 30);
	me->add("force", -20);

	return 1;
}

string perform_action_file(string func)
{
	return CLASS_D("bibotan") + "/chuanyun-tui/" + func;
}


