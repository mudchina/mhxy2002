// created by ken,pnt 2001.3.9 tianxian-sword
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "name":                 "九弧震日",
                "action":               "$N凝神提气，凌空跃起，一招「九弧震日」，手中$w如烈阳洒向$n的$l，没有人知道剑从哪里来，也就无法抵挡",
                "dodge":                -20,
                "parry" :               -10,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "无孔不入",
                "action":               "$N手中的$w突转，无孔不入的刺向$n的$l",
                "dodge":                -10,
                "parry" :               -10,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "飞星传恨",
                "action":               "$N舞动$w，一招「飞星传恨」，剑如飞星人如闪电，人剑合一，扑向$n的$l",
                "dodge":                -10,
                "parry" :               -10,
                "damage":                35,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "日在九天",
                "action":               "$N一抖手中$w，使出「日在九天」，不由得豪情壮志，以意驭剑，向$n的$l刺出一剑",
                "dodge":                -10,
                "parry" :               -10,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "天河倒泻",
                "action":               "$N手中$w剑光四散，剑光如雾，笼罩了$n的$l，令人不知剑来自何方",
                "dodge":                -15,
                "parry" :               -15,
                "damage":               20,
                "damage_type":  "刺伤"
        ]),
        ([      "name":                 "佳期如梦",
                "action":               "$N想起年少玩伴尢在倚门相望，手中$w直指$n$l，一招「佳期如梦」，刺出了惊天动地的一剑",
                "dodge":                -10,
                "parry":                -20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":"$N一式「天外飞仙」，$w突然从天而降，一片金光围掠$n全身",
                 "dodge" :               -25,
                 "parry" :               -25,
                 "damage":                40,
                 "damage_type":  "刺伤"
        ]),
        ([      "action":
"只见$N笑声不断，全身亦似一无戒备，待$n一愣之际手中$w一招「天外流星」向$n的$1削斜而出",
                "damage":               40,
                "dodge":                -20,
                "parry":                -15,
                "damage_type":      "割伤",
        ]),
/*
   ([   "action":
HIY"$N身形突转，御剑回飞！"NOR,
     "dodge":     -70,
     "parry":     -70,
     "damage":     15,
     "damage_type":   "刺伤"
   ]),
*/
});

int valid_learn(object me)
{
        object ob;

if(me->query("family/master_id") != "master long")
            return notify_fail("你虽会天仙剑法但不知如何练习。\n");
   if (me->query("betray/count"))
             return notify_fail("你求学之心不专，无缘学得天仙剑法。\n");
   if(me->query("family/family_name") != "魔教")
             return notify_fail("天仙剑法乃无恨不传绝学！\n");
   if( (string)me->query_skill_mapped("force")!= "evil-force")
             return notify_fail("天仙剑法需配合血魔神功才可发挥威力。\n");
        if( (int)me->query("max_force") < 150 )
                return notify_fail("你的内力不够，无法学习剑法。\n");
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你得先找把剑来才能练剑法．\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword" || usage=="parry";
}

/*
mapping query_action(object me, object weapon)
{
        int i;

        i=me->query_temp("TXJ_perform");
        if(!me->query_temp("TXJ_perform")) {
                return action[random(8)];
        }else {
                return action[i];
        }
   }
*/
mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}
int practice_skill(object me)
{
        object weapon;
        
if(me->query("family/master_id") != "master long")
                return notify_fail("你虽会天仙剑法，不知如何练习这招。\n");
        if (me->query("betray/count"))
                return notify_fail("你判师欺祖，无缘学得天仙剑法。\n");
        if( (string)me->query_skill_mapped("force")!= "evil-force")
                return notify_fail("天仙剑法需配合血魔神功才能练习．\n");
        if( !objectp(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
                return notify_fail("手中无剑，如何练习剑法？\n");

        if( (int)me->query("kee") < 50 
        ||    (int)me->query("force") < 30)
                return notify_fail("你的体力不够，还是先休息休息吧。\n");
        me->receive_damage("kee", 50);
        me->add("force", -10);
        write("你眼前幻出道道剑影，心中如有所悟。\n");
        return 1;
}


string perform_action_file(string action)
{
        return CLASS_D("evil") + "/tianxian-sword/" + action;
}
