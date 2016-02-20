//by lovezhe@mhxy for 2001.12.22
//Cracked by Roath

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "朱雀降世",
                "action":
"$N手中$w一抖，一招"+RED"「朱雀降世」"NOR"$N高高跃起，由如展翅腾飞的朱雀压向$n，$N手中$w直奔$n的$l刺去",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "朱雀狂舞",
                "action":               "$N身形一转，暴喝一声，手中$w突然射出无数如同朱雀火羽的剑气连续刺向$n的$l,好一招"+RED"「朱雀狂舞」"NOR"",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "朱雀乱舞",
                "action":
"$N舞动$w，突然一个疾冲，一招"+RED"「朱雀乱舞」"NOR",$w挟着如火如涂剑气刺向$n的$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "朱雀血舞",
                "action":
"$N手中$w一抖，幻出几许金光，就在一恍惚间，这招"+RED"「朱雀血舞」"NOR"$w已斜斜地点上了$n的$l",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "朱雀火舞",
                "action":
"$N运起四像神功的朱雀决，神焰立刻注入手中的$w，一招"+RED"「朱雀火舞」"NOR",又急又快地往$n$l刺去",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "朱雀闪身",
                "action":
"$N猛然间身形一展，手中$w突发几尺剑芒，唰地刺向了$n的$l,好一招"+RED"「朱雀闪身」"NOR"",
		"parry":		-10,
                "dodge":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "朱雀腾空",
                "action":               
"$N大喝一声，手中$w宛若凤凰飞在半空，大有"+RED"「朱雀腾空」"NOR"的气概。\n$n只觉得全身俱在$w笼罩之下",
                "dodge":                -10,
                "parry":                -10,
                "damage":               90,
                "damage_type":  "抽伤"
        ]),
        ([      "name":                 "朱雀甩尾",
                "action":
"$N你一声神嚎，已经与手中的$w化为一体，不顾一切地冲向$n，几乎与$n贴脸而至之时突然一个转身！\n手中$w却悄无声息地刺向$n的$l，好厉害的"+RED"「朱雀甩尾」"NOR"",
                "dodge":                -10,
                "parry":                -10,
                "damage":               90,
                "damage_type":  "刺伤"
        ]),


});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("你的内力不够，没有办法练朱雀剑。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
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
	string name;
	mapping actions;

        i=me->query("HellZhen");
        if( !me->query("HellZhen") ) {
        actions=action[random(6)];
        }else {
        actions=action[i];
        }

	name=actions["name"];
	me->set_temp("kill_msg","special_msg");
	me->set_temp("special_msg",name);

	return actions;
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 5 )
                return notify_fail("你的内力或气不够，没有办法练习朱雀剑。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("你按着所学练了一遍朱雀剑。\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

void skill_improved(object me)
{
        if( (int)me->query_skill("zhuque-sword", 1)  % 10 == 0 ) {
                tell_object(me,
                        RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
                me->add("bellicosity", 100);
        } else
                me->add("bellicosity", 10);
}

string perform_action_file(string func)
{
return CLASS_D("ghost") + "/zhuque-sword/" + func;
}


