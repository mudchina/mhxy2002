//光明大手印
//create by focus 2001.2.10


inherit SKILL;
#include <ansi.h>

mapping *action = ({
        ([      "name":    "不空成就佛大手印",
                "action":               HIC"$N双手中间三指相交插互扣握住，姆指、小指则相并竖起, 立即一股无可\n"+"匹敌的劲气三贯而出，直向$n撞去"NOR,
                "dodge":                10,
                "parry":                10,
                "force":                120,
                "damage_type":  "刺伤",
                "weapon":      "手指"
        ]),
        ([      "name":     "金刚界大手印",
                "action": HIC"$N姆指小指左右两手指尖相碰，中间三指各插入另手三指之间平举！翻掌推出,\n"+
                          "一股讯猛的劲气直向$n当头罩下"NOR,
                "dodge":                5,
                "parry":                -15,
                "force":                180,
                "damage_type":  "砸伤",
        ]),
        ([      "name":      "如来拳印",
                "action":    HIY"只见$N左手四指内曲往手掌，姆指直竖，右手下面三指握住左手姆指，食指、姆指扣成一圆环。\n"+"环内射出一股劲气，点向$n的$l"NOR,
                "dodge":                5,
                "parry":                10,
                "force":                130,
                "damage_type":  "内伤",
        ]),
        ([      "name":      "尊胜空印",
                "action":    HIW"$N将左右手的姆指、食指各自成一圆形相并，再各自将左右手后三指竖起合掌。劈向$n的$l"NOR,
                "dodge":                20,
                "parry":                20,
                "force":                140,
                "damage_type":  "砸伤",
        ]),
            ([  "name":      "军荼利羯摩印",
                "action":    HIB"$N将左、右手腕交叉。右手腕在内，左手腕在外。两手掌姿势各别将姆指、小指指尖成一环；\n"+"中间三指竖起微张,弹向$n的$l"NOR,
                "dodge":                30,
                "parry":                10,
                "force":                160,
//              "damage_type":  "刺伤",
        ]),
            ([  "name":      "修菩提心妙观察智弥陀印",
                "action":    HIY"$N双掌平举于胸前，左、右手个自拇指、食指成一扣环,而后面三指的相互交插，平放于腹前气海丹田穴之间，\n"+
                "交叉六指快速弹出六道剑气，直奔$n的$l而去"NOR,
                "dodge":                10,
                "parry":                -10,
                "force":                220,
//              "damage_type":  "砍伤",
        ]),
        ([      "name":      "不动明王手印",
                "action":    HIR"$N低眉瞑目，右手中指、食指骈伸；以左手拇指、无名指、小指握住。同时，左手中指、食指亦骈伸所结成的大手印，\n"+"全身气机冲掌而出，一淡淡手印影像，忽变大倍许，击向$n"NOR,
                "dodge":                -50,
                "parry":                -50,
                "force":                520,
                "damage_type":  "内伤",
         ]),
});

int valid_learn(object me)
{
        
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练光明大手印必须空手。\n");
        return 1;
}
int valid_enable(string usage)
{
        return usage=="unarmed"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
 /*       int i;
        i=me->query_temp("pfm_shouyin");
        if( !me->query_temp("pfm_shouyin") ) 
        {
              return action[random(6)];
        }   
    else 
        {
              return action[i];
        }*/ 
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 20 )
                return notify_fail("你的内力或气血不够，没有办法练习光明大手印。\n");
        me->receive_damage("kee", 30);
        me->add("force", -15);
        write("你按着所学练了一遍光明大手印。\n");
        return 1;

}

string perform_action_file(string func)
{
return CLASS_D("lingjie") + "/guangming-shouyin/" + func;
}
