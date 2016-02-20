// link 2001.2.16
#include <ansi.h>
inherit SKILL;
mapping *action = ({
	([	"action":		"$N使出灵幡九阴中的起手式“仇恨生天阴”，手中的$w划出一溜光芒斩向$n的$l",
		"force":		500,
		"damage_type":	"割伤"
	]),
	([	"action":		"$N手一抖，一招“恶毒生地阴”手中的$w幻成一片伞花，散向$n的$l",
		"force":		400,
		"damage_type":	"砸伤"
	]),
	([	"action":		"$N伞柄忽转，手中的$w一招“怨气生人阴”，闪电般劈向$n的$l",
		"force":		300,
		"damage_type":	"砸伤"
	]),
	([	"action":		"$N身影晃动，伞锋忽左忽右，一招“反叛生日阴”，手中的$w，从中路突然砍至$n的$l",
		"force":		300,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N的双脚点地，伞背贴身，一招“遗弃生星阴”全身转出一团伞光滚向$n",
		"force":		300,
		"damage_type":	"淤伤"
	]),
	([	"action":		"$N伞刃向上，一招“生离生法阴”，从一个$n意想不到的角度撩向$n的$l",
		"force":		200,
		"damage_type":	"刺伤"
	]),
	([	"action":		"$N你手中的$w左右横划，一招“死别生玄阴”，来来回回地狂扫向$n的$l",
		"force":		300,
		"damage_type":	"割伤"
	]),
        ([      "action":               "$N使出灵幡九阴中的收手式“天劫生气阴”，手中的$w迅捷无比地砍向$n的$l",
                "force":                600,
                "damage_type":  "砸伤"
        ]),
});

mapping query_action(object me)
{
    if (random(me->query_skill("umbrella",1)) > 50 &&
        me->query_skill("force",1) > 200 &&
        me->query("force") > 200 ) {
             me->add("force", -200);
             return ([
                  "action": "$N咬破舌尖，口中喷血，吐在伞上，聚集全身的力量击向$n",
                  "force": 1000,
                  "damage_type": "割伤"]);
    }
    return action[random(sizeof(action))];
}


int valid_learn(object me)
{
        if( (int)me->query_skill("force", 1) < 200 )
                return
                notify_fail("你的内功心法火候不足，无法练灵幡九阴。\n");
        if( (int)me->query_skill("guangming-force", 1) < 200 )
                return
		notify_fail("你的光明心法火候不足，无法练灵幡九阴。\n");
	return 1;
}

int valid_enable(string usage)
{
	return (usage=="umbrella") || (usage=="parry");
}


int practice_skill(object me)
{
	object weapon;

	if( !objectp(weapon = me->query_temp("weapon"))
	||	(string)weapon->query("skill_type") != "umbrella" )
		return notify_fail("你必须先找一把伞，才能练伞法。\n");

	if( (int)me->query("kee") < 80 )
		return notify_fail("你的体力不够练这门刀法，还是先休息休息吧。\n");
	me->receive_damage("kee", 80);
	return 1;
}
int effective_level() { return 50;}

string *parry_msg = ({
	"$n使出灵幡九阴中的真谛“怨恨劫毒离弃悲哀叛”，手中的$v化成九重伞幕护住全身。\n",
});

string *unarmed_parry_msg = ({
        "$n使出灵幡九阴中的真谛“怨恨劫毒离弃悲哀叛”，手中的$v化成九重伞幕护住全身。\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return umbrella_parry_msg[random(sizeof(umbrella_parry_msg))];
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return -5;
}
int black_white_ness()
{
	return 20;
}

string perform_action_file(string action)
{
        return CLASS_D("lingjie") + "/lingfan-san/" + action;
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
    int i=random(10);
    if( damage_bonus < 100 ) return 0;
    if (me->query("force")<=200) return 0;
    if(random(me->query_skill("lingfan-san", 1)) > 40
       &&i>7&&me->query_skill("lingfan-san", 1) > victim->query_skill("lingfan-san", 1)
       && (me->query("force") + me->query("con")*30) > victim->query("force")){
       if(victim->query_skill("force")/2 < me->query_skill("force")){
          victim->apply_condition("yun_poison", 2+victim->query_condition("yun_poison"));
	me->add("force",-200);
	message_vision(YEL"$N被转晕了！\n"NOR,victim);}
       else {me->apply_condition("yun_poison", 1+victim->query_condition("yun_poison"));
	me->add("force",-200);
	message_vision(YEL"$N害人不成，反而自己被转晕了！\n"NOR,me);}
        }
}